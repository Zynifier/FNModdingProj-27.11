// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MeshBeaconClient.h"
#include "FortMeshBeaconClient.generated.h"

UCLASS()
class AFortMeshBeaconClient : public AMeshBeaconClient
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_GameplayTagIndexHash();

	UPROPERTY(ReplicatedUsing=OnRep_GameplayTagIndexHash)
	uint32 GameplayTagIndexHash;

	UPROPERTY(Config)
	bool bIgnoreFailedUpdateLevelVisibilityValidation;

};

