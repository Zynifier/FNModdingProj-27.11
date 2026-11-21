// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Curie/FortCurieManagerComponent.h"
#include "CurieManagerComponent.h"
#include "FortCurieIcePropagationManager.generated.h"

class AActor;
class ABuildingGameplayActor;
class AController;
class UFortCurieIcePropagationManagerConfig;
class UPrimitiveComponent;

UCLASS(MinimalAPI)
class UFortCurieIcePropagationManager : public UFortCurieManagerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnIceBlockDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCurieIcePropagationManagerConfig> InternalManagerConfig;

};

UCLASS()
class UFortCurieIcePropagationManagerConfig : public UCurieManagerComponentConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieIcePropagationManagerConfig")
	float IceBlockSeparation;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieIcePropagationManagerConfig")
	TSubclassOf<ABuildingGameplayActor> IceBlockClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieIcePropagationManagerConfig")
	float PropagationRate;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieIcePropagationManagerConfig")
	int32 DefaultPropagationDepth;

};

