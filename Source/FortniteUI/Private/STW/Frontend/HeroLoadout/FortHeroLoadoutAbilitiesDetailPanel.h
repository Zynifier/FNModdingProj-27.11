// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item/FortItemDetailsHostPanel.h"
#include "FortHeroLoadoutAbilitiesDetailPanel.generated.h"

UCLASS(Abstract, BlueprintType)
class UFortHeroLoadoutAbilitiesDetailPanel : public UFortItemDetailElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ListenForChanges(bool bListen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerHomebaseChanged();

};

