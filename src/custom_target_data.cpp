#include "custom_target_data.h"

#include <fmt/core.h>

#include <opencv2/imgproc.hpp>

using namespace deadeye;
using namespace custom;
using json = nlohmann::json;

CustomTargetData::CustomTargetData(std::string id, int sn, bool valid,
                                   cv::Rect bb)
    : TargetData{id, sn, valid}, bb(bb), center((bb.tl() + bb.br()) / 2) {}

void CustomTargetData::DrawMarkers(cv::Mat& preview) const {
  cv::drawMarker(preview, center, cv::Scalar::all(255));
  cv::rectangle(preview, bb, cv::Scalar(255, 0, 0));
}

std::string CustomTargetData::Dump() const {
  json j =
      json{{TargetData::kIdKey, id},
           {TargetData::kSerialKey, serial},
           {TargetData::kValidKey, valid},
           {TargetData::kDataKey,
            {bb.tl().x, bb.tl().y, bb.br().x, bb.br().y, center.x, center.y}}};
  return j.dump();
}

std::string CustomTargetData::ToString() const {
  return fmt::format("id={} sn={} val={} tl=({},{}) br=({},{}) off=({},{})", id,
                     serial, valid, bb.tl().x, bb.tl().y, bb.br().x, bb.br().y,
                     center.x, center.y);
}
