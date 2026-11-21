// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/FortLayeredAudioComponent.h"
#include "FortGliderAudioComponent.generated.h"

class AFortPlayerParachute;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortGliderAudioComponent : public UFortLayeredAudioComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsParachuteFullyDeployed() const;

	UFUNCTION(BlueprintCallable)
	void UpdateGliderAudio(float ForwardDot, float RightDot);

	UPROPERTY(EditDefaultsOnly, Category="FortGliderAudioComponent")
	bool bDebugIgnoreFullyDeployed;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerParachute> PlayerParachute;

};

