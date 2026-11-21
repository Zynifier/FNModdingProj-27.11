// Copyright Epic Games, Inc. All Rights Reserved.

#include "DataSource/SingleValue/Implementations/FortStandardGlobalActionDetailsDataSource.h"

UFortStandardGlobalActionDetailsDataSource* UFortStandardGlobalActionDetailsDataSource::Construct(UObject* Outer, UFortGlobalUIContext* GlobalUIContext, UCommonInputSubsystem* CommonInputSubsystem, EFortGlobalAction GlobalAction, const FFortGlobalActionDetailsFunctionContext& ActionDetailsContext)
{
	return nullptr;
}

UFortStandardGlobalActionDetailsDataSource* UFortStandardGlobalActionDetailsDataSource::ConstructWithDefaultContexts(UObject* Outer, UWidget* ContextWidget, EFortGlobalAction GlobalAction, const FFortGlobalActionDetailsFunctionContext& ActionDetailsContext)
{
	return nullptr;
}

void UFortStandardGlobalActionDetailsDataSource::HandlePlayerControllerChanged(UObject* Source)
{
}

void UFortStandardGlobalActionDetailsDataSource::SetActionDetailsContext(const FFortGlobalActionDetailsFunctionContext& Value)
{
}

void UFortStandardGlobalActionDetailsDataSource::SetCommonInputSubsystem(UCommonInputSubsystem* Value)
{
}

void UFortStandardGlobalActionDetailsDataSource::SetGlobalAction(EFortGlobalAction Value)
{
}

void UFortStandardGlobalActionDetailsDataSource::SetGlobalUIContext(UFortGlobalUIContext* Value)
{
}
