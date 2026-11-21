// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "ThreatCloud.generated.h"

class ABuildingRift;
class UBoxComponent;
enum class EFortThreatDeactivationType : uint8;

UENUM(BlueprintType)
enum class EFortThreatDeactivationType : uint8
{
	Off = 0,
	// Turn the threat cloud off (hide)

	Dormant = 1,
};

UCLASS(BlueprintType, Blueprintable)
class AThreatCloud : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ThreatCloud")
	FBox GetThreatVolume() const;

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void ManualLightningFlash();

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void OnCloudActivated();

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void OnCloudDeactivated(EFortThreatDeactivationType DeactivationType);

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void OnCloudHiddenChange(bool bCloudsAreHidden);

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void OnCloudStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="ThreatCloud")
	void OnLightningStrike(const FVector& StartLocation, const FVector& EndLocation, ABuildingRift* Rift, bool bLightningStruckRift);

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void OnThreatVolumeChanged();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="ThreatCloud")
	void OnBeginDeath();

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="ThreatCloud", meta=(EditInline="true"))
	TArray<TObjectPtr<UBoxComponent>> LightningSourceAreas;

private:
	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	float MiniMapIconPercent;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapFarOffIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor ActiveTint;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor InActiveTint;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	float ActiveTransitionTime;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud")
	float DeathTimerDuration;

	UPROPERTY(Transient)
	float CloudMiniMapTickInterval;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	float MiniMapFarOffIconDegreesOfArc;

	UPROPERTY(Transient)
	FBox ThreatBoxVolume;

	UPROPERTY(Transient)
	float GroundLevelUnderCloud;

	UPROPERTY(Transient)
	TArray<FVector> GoalActorLocations;

};

