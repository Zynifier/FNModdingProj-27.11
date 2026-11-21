// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortVehicleTeleportPortal.h"
#include "Building/BuildingGameplayActorConsumable.h"
#include "FortAthenaRiftPortal.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaRiftPortal : public ABuildingGameplayActorConsumable, public IVehicleTeleportPortal
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddIgnoredActor(const AActor* Actor);

	UFUNCTION(BlueprintPure)
	bool IsIgnoredActor(const AActor* QueryActor) const;

	UFUNCTION(BlueprintNativeEvent)
	void NotifyTeleportedVehicle(AActor* VehicleActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OverlappingOnBeginPlay(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void TeleportVehicle(AActor* Vehicle, const FVector& TeleportLocation);

	UFUNCTION(BlueprintCallable)
	void TeleportVehicleFacing(AActor* Vehicle, const FVector& TeleportLocation, const FRotator& Rot);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaRiftPortal")
	FGameplayTag IgnoreActorTag;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Filters", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	TArray<TObjectPtr<AActor>> IgnoredActors;

};

