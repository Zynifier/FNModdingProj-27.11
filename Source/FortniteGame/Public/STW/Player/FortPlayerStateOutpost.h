// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Player/FortPlayerStatePvE.h"
#include "FortPlayerStateOutpost.generated.h"

class AFortPlayerStateOutpost;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayerStateOutpost : public AFortPlayerStatePvE
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Outpost")
	bool HasPermissionToEditOutpost() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	bool IsOutpostOwner() const;

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void SetHasPermissionToEditOutpost(AFortPlayerStateOutpost* InPlayer, bool bHasPermission);

protected:
	UFUNCTION()
	void OnRep_HasPermissionToEditOutpost();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetHasPermissionToEditOutpost(AFortPlayerStateOutpost* InPlayer, bool bHasPermission);

	UPROPERTY(ReplicatedUsing=OnRep_HasPermissionToEditOutpost)
	bool bHasPermissionToEditOutpost;

};

