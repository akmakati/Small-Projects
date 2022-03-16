
function load_barchartIris(svg_name,data){

    // General Variables
    let chart = d3.select(svg_name);
    let chart_width  = $(svg_name).width();
    let chart_height = $(svg_name).height();

    // x position scale
	let x = d3.scaleBand()
            .padding(0.2)
    		.domain(data.map(function (d) {return d.class}))
		    .range([70,chart_width-100]);

	// x axis scale
	xAxis = d3.axisBottom()
			.scale(x)
	var xAxisGroup = chart.append("g")
			.attr("class", "axis")
			.attr("transform", "translate(0," + (chart_height-40) + ")")
			.call(xAxis);

	// x axis label
	chart.append("text")
			.text("Iris Class")
			//.attr("transform", "rotate(90) " )
			.attr("y", 490)
			.attr("x", 450)
			.attr("font-weight",function(d,i) {return 750;})
			.style("text-anchor", "end");

	// y position scale
	let y = d3.scaleLinear()
			//.domain(d3.extent(data,function(d){ return d.research; }))
            .domain([4, 8])
			.range([chart_height-50,70]);

	// y axis scale
	yAxis = d3.axisLeft()
			.scale(y)
	var yAxisGroup = chart.append("g")
			.attr("class", "axis")
			.attr("transform", "translate(60, 0)")
			.call(yAxis);

	// y axis label
	chart.append("text")
			.text("Average Sepal Length")
			.attr("class", "y label")
			.attr("text-anchor", "end")
			.attr("y", 20)
			.attr("x", -175)
			.attr("transform", "rotate(-90)")
			.attr("font-weight",function(d,i) {return 750;});

	// Chart Title
	chart.append("text")
			.text("Average Sepal Length of Different Iris Classes")
			.attr("y", 50)
			.attr("x", 600)
			.attr("font-weight",function(d,i) {return 750;})		
			.style("text-anchor", "end")
			.attr("transform", "rotate(0) " );

	
	//COLOR
	var color = d3.scaleOrdinal(["#AE2EA9","#4283E5", "#92D029"])
	//BAR CHART
	chart.selectAll("mybar")
      		.data(data)
            .enter()
            .append("rect")
      		.attr("x", function (data) { return x(data.class); })
            .attr("y", function (data) { return y(data.avg); })
            .attr("height", function (data) { return 451 - y(data.avg); })
            .attr("width", x.bandwidth())
            .attr("fill", function(d, i) {
				return color(i);
			})
// LEGEND
chart.append("circle")
	.attr("cx", 780)
	.attr("cy", 100)
	.attr("r", 8)
	.style("fill", "#AE2EA9")
chart.append("circle")
	.attr("cx", 780)
	.attr("cy", 120)
	.attr("r", 8)
	.style("fill", "#4283E5")
chart.append("circle")
	.attr("cx", 780)
	.attr("cy", 140)
	.attr("r", 8)
	.style("fill", "#92D029")
chart.append("text")
	.text("Iris-setosa")
	.attr("x", 800)
	.attr("y", 100)
	.style("font-size", "12px")
	.attr("alignment-baseline", "middle")
chart.append("text")
	.text("Iris-versicolor")
	.attr("x", 800)
	.attr("y", 120)
	.style("font-size", "12px")
	.attr("alignment-baseline", "middle")
chart.append("text")
	.text("Iris-virginica")
	.attr("x", 800)
	.attr("y", 140)
	.style("font-size", "12px")
	.attr("alignment-baseline", "middle")


    // return chart data that can be used later
	return {
		chart : chart,
		chart_width : chart_width,
		chart_height : chart_height,
		x_scale : x,
		y_scale : y,
		//points : points
	}
	/*
	I referenced the following code.
	https://www.d3-graph-gallery.com/graph/barplot_basic.html
	*/
}