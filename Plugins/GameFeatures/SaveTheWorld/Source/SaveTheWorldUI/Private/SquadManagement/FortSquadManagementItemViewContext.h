// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item/FortItemViewContextInterface.h"
#include "FortSquadManagementItemViewContext.generated.h"

UCLASS(Abstract)
class UFortSquadManagementItemViewContextBase : public UObject, public IFortItemViewContextInterface
{
	GENERATED_BODY()

};

UCLASS()
class UFortItemViewContext_SquadSlotItemPicker : public UFortSquadManagementItemViewContextBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortItemViewContext_ExpeditionSquadSlotItemPicker : public UFortItemViewContext_SquadSlotItemPicker
{
	GENERATED_BODY()

};

UCLASS()
class UFortItemViewContext_SquadSlotsView : public UFortSquadManagementItemViewContextBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortItemViewContext_ExpeditionSquadSlotsView : public UFortItemViewContext_SquadSlotsView
{
	GENERATED_BODY()

};

