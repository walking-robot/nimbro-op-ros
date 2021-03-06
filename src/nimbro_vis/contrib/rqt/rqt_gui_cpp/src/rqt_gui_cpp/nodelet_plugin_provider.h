/*
 * Copyright (c) 2011, Dirk Thomas, TU Darmstadt
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the TU Darmstadt nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef rqt_gui_cpp__NodeletPluginProvider_H
#define rqt_gui_cpp__NodeletPluginProvider_H

#include <qt_gui_cpp/ros_pluginlib_plugin_provider.h>

#include <rqt_gui_cpp/plugin.h>

#include <nodelet/loader.h>
#include <nodelet/nodelet.h>

#include <string>

namespace rqt_gui_cpp {

class RosCppPluginProvider;

class NodeletPluginProvider
  : public qt_gui_cpp::RosPluginlibPluginProvider<rqt_gui_cpp::Plugin>
{

public:

  NodeletPluginProvider(const QString& export_tag, const QString& base_class_type);

  virtual ~NodeletPluginProvider();

  virtual void unload(void* instance);

protected:

  void init_loader();

  virtual boost::shared_ptr<Plugin> create_plugin(const std::string& lookup_name, qt_gui_cpp::PluginContext* plugin_context);

  boost::shared_ptr<nodelet::Nodelet> create_instance(const std::string& lookup_name);

  virtual void init_plugin(const QString& plugin_id, qt_gui_cpp::PluginContext* plugin_context, qt_gui_cpp::Plugin* plugin);

  nodelet::Loader* loader_;

  boost::shared_ptr<rqt_gui_cpp::Plugin> instance_;

  QMap<void*, QString> instances_;

};

}

#endif // rqt_gui_cpp__NodeletPluginProvider_H
