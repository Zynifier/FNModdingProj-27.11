// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityActorComponent.h"
#include "ParticleSystemComponentBase.generated.h"

class UVerseAssetPtr;

UCLASS(Abstract)
class UParticleSystemComponentBase : public UEntityActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_bActive();

	UFUNCTION()
	void OnRep_ParticleSystemAsset();

	UPROPERTY(ReplicatedUsing=OnRep_ParticleSystemAsset)
	TObjectPtr<UVerseAssetPtr> ParticleSystemAsset;

	UPROPERTY(ReplicatedUsing=OnRep_bActive)
	bool bActive;

};

