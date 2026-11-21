// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_VictoryCrownsFrontEnd.generated.h"

class UDataTable;
class UFortSocialParty;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortPawnComponent_VictoryCrownsFrontEnd : public UFortPawnComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlaylistChanged();

	UPROPERTY(EditDefaultsOnly, Category="FortPawnComponent_VictoryCrownsFrontEnd", meta=(RowType="/Script/VictoryCrownsRuntime.VictoryCrownPlaylistData"))
	TObjectPtr<UDataTable> VictoryCrownPlaylistData;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnComponent_VictoryCrownsFrontEnd")
	bool bInitializeSuccess;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnComponent_VictoryCrownsFrontEnd")
	bool bSelectedPlaylistSupportCrown;

	UPROPERTY(Transient)
	TObjectPtr<UFortSocialParty> PersistentParty;

};

