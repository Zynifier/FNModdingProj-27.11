// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "SafeZoneLocation.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class ASafeZoneLocation : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

private:
	UPROPERTY(EditDefaultsOnly, Export, Category="Storm Shield", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PreviewShieldRing;

	UPROPERTY(EditAnywhere, Category="SafeZoneLocation")
	FGameplayTag LocationTag;

	UPROPERTY(EditAnywhere, Transient, Category="SafeZoneLocation")
	float PreviewZScale;

	UPROPERTY(EditAnywhere, Category="SafeZoneLocation")
	float SafeZoneRadius;

};

