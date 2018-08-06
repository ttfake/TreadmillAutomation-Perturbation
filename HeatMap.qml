import QtQuick 1.1
 import "components"

 // Here is a simple heat map:

 HeatMap {
     id: heatmap
     width: 400
     height: 200
     radius: 20
     max: 20
     min: 0
     calculateIntensity: true
     intensity: 0
 }

 // The data model is as follows:
 // x and y are the coordinates in relation to the center of the heat map.
 // count is the data that is to be used if the intensity is to be calculated.

 ListModel {
     id: data
     ListElement {
         x: 10
         y: 20
         count: 18
     }

     ListElement {
         x: 25
         y: 50
         count: 14
     }

     ListElement {
         x: -50
         y: -10
         count: 10
     }

     ListElement {
         x: 12
         y: 22
         count: 16
     }

     ListElement {
         x: 1
         y: 2
         count: 4
     }
 }

 // This is an example function to populate the data model of the heatmap.
 function populateHeatMap()
 {
     heatmap.model.clear();
     var xMin = -heatmap.width/2;
     var xMax = heatmap.width/2;
     var yMin = -heatmap.height/2;
     var yMax = heatmap.height/2;

     for (var i=0; i < 200; i++)
     {
         var data = {"x": getRandomInt(xMin, xMax), "y": getRandomInt(yMin, yMax), "count": getRandomInt(heatmap.min, heatmap.max)};
         heatmap.model.append(data);
     }

 }

 function getRandomInt(min, max) {
     return Math.floor(Math.random() * (max - min + 1)) + min;
 }
