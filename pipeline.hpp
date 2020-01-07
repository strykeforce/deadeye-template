#pragma once

#include "pipeline/abstract_pipeline.hpp"

using namespace deadeye;

namespace ded {
class TestPatternPipeline : public AbstractPipeline {
 public:
  TestPatternPipeline(int inum) : AbstractPipeline{inum} {}

 protected:
  virtual cv::VideoCapture GetVideoCapture() override;

  virtual void FilterContours(
      std::vector<std::vector<cv::Point>> const &src,
      std::vector<std::vector<cv::Point>> &dest) override;

  virtual std::string ToString() const override;
};

}  // namespace ded
