// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortUpgradeTileBase_Legacy.generated.h"

class UFortUpgradeInfo;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortUpgradeTileBase_Legacy : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDataRefresh(bool bUpgrade);

	UPROPERTY(BlueprintReadOnly, Category="FortUpgradeTile")
	TObjectPtr<UFortUpgradeInfo> UpgradeInfo;

};

