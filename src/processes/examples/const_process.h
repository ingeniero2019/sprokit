/*ckwg +5
 * Copyright 2011 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef VISTK_PROCESSES_EXAMPLES_CONST_PROCESS_H
#define VISTK_PROCESSES_EXAMPLES_CONST_PROCESS_H

#include "examples-config.h"

#include <vistk/pipeline/process.h>

namespace vistk
{

/**
 * \class const_process
 *
 * \brief A process which has a const output port.
 *
 * \process A process with a const output port.
 *
 * \oports
 *
 * \oport{const} The datum generated for the step.
 *
 * \reqs
 *
 * \req The \port{const} output must be connected to at least one edge.
 */
class VISTK_PROCESSES_EXAMPLES_NO_EXPORT const_process
  : public process
{
  public:
    /**
     * \brief Constructor.
     *
     * \param config Contains config for the process.
     */
    const_process(config_t const& config);
    /**
     * \brief Destructor.
     */
    ~const_process();
  protected:
    /**
     * \brief Pushes a new number through the output edge.
     */
    void _step();

    /**
     * \brief Connects an edge to an output port on the process.
     *
     * \param port The port to connect to.
     * \param edge The edge to connect to the port.
     */
    void _connect_output_port(port_t const& port, edge_t edge);

    /**
     * \brief Information about an output port on the process.
     *
     * \throws no_such_port_exception_exception Thrown when \p port does not exist on the process.
     *
     * \param port The port to return information about.
     *
     * \returns Information about the output port.
     */
    port_info_t _output_port_info(port_t const& port) const;

    /**
     * \brief Lists the ports available on the process.
     */
    ports_t _output_ports() const;
  private:
    class priv;
    boost::shared_ptr<priv> d;
};

}

#endif // VISTK_PROCESSES_EXAMPLES_CONST_PROCESS_H