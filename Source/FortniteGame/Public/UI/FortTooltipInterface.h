// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTooltipInterface.generated.h"

class UFortTooltip;
class UFortTooltipDisplayStatsList;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortTooltipInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortTooltipInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tooltips")
	virtual UFortTooltipDisplayStatsList* GetDisplayStats() const;

	UFUNCTION(BlueprintCallable, Category="Tooltips")
	virtual TSubclassOf<UFortTooltip> GetTooltip(bool bSummaryTooltip = false) const;

};

