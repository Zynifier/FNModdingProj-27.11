// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "FortMissionStormSafeZone.generated.h"

class ABuildingActor;
class AFortPlayerPawn;
class UAbilitySystemComponent;
class UFortGameplayAbility;
class UStaticMeshComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSafeZoneInStormStateChanged, bool, bInStorm);

UCLASS(BlueprintType, Blueprintable)
class AFortMissionStormSafeZone : public AActor, public IFortAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mission Safe Zone")
	float GetConvertedSafeZoneRadius() const;

	UFUNCTION(BlueprintPure, Category="Mission Safe Zone")
	float GetSafeZoneRadius() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Safe Zone")
	void OnPlayerPlacedBuildingActorInRadius(const ABuildingActor* BuildingPlaced, const AFortPlayerPawn* ByPlayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Safe Zone")
	void OnSafeZoneRadiusChanged(const float NewRadius, const float NewConvertedRadius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Mission Safe Zone")
	void SetSafeZoneRadius(const float InRadius);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortMissionStormSafeZone", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SafeZoneMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mission Safe Zone")
	bool bScaleUniformly;

	UPROPERTY(BlueprintAssignable, Category="Mission Safe Zone")
	FOnSafeZoneInStormStateChanged OnSafeZoneInStormStateChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Safe Zone")
	TArray<TSubclassOf<UFortGameplayAbility>> Abilities;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UFUNCTION()
	void OnRep_SafeZoneInStormStateChanged();

	UFUNCTION()
	void OnRep_ZoneRadius();

	UPROPERTY(ReplicatedUsing=OnRep_SafeZoneInStormStateChanged)
	bool bSafeZoneInStormStateChanged;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ZoneRadius, Category="Mission Safe Zone")
	float SafeZoneRadius;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilityComponent;

};

