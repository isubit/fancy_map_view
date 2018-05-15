(function ($) {
  "use strict";

  var fancyMapView = Drupal.fancyMapView = Drupal.fancyMapView || {};

  Drupal.behaviors.fancyMapView = {
    attach: function(context, settings) {
      $('html', context).once('fancyMapView', function() {
        fancyMapView.addMap(settings);
      });
    }
  };

  fancyMapView.addMap = function(settings) {

    if (settings.fancyMapView && settings.fancyMapView.features) {

      fancyMapView.map = new google.maps.Map(
        document.getElementById('fancy-map-view-canvas'), {
          gestureHandling: 'greedy',
          panControl: false,
          mapTypeControl: true,
          scaleControl: false,
          streetViewControl: false,
          overviewMapControl: false,
          zoomControl: true,
          zoomControlOptions: {
            style: google.maps.ZoomControlStyle.SMALL,
            position: google.maps.ControlPosition.LEFT_BOTTOM
          },
          mapTypeId: google.maps.MapTypeId.ROADMAP,
          zoom: 4,
          center: {
            lat: 42.0301381,
            lng: -93.6501248
          }
        }
      );

      if (typeof fancyMapView.mapDataInit === 'function') {
        fancyMapView.mapDataInit(fancyMapView.map, settings.fancyMapView.features.features);
      } else {
        fancyMapView.map.data.addGeoJson(settings.fancyMapView.view.features);
        if (window.location.href.indexOf('?') !== -1) {
          fancyMapView.fitBounds(fancyMapView.map, settings.fancyMapView.features.features);
        }
      }

    }

  };

  fancyMapView.fitBounds = function(map, features) {

    var bounds = new google.maps.LatLngBounds();

    features.forEach(function(feature) {
      bounds.extend(new google.maps.LatLng(feature.geometry.coordinates[1], feature.geometry.coordinates[0]));
    });

    map.fitBounds(bounds);

  };

})(jQuery);