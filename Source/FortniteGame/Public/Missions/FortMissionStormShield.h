// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Creative/FortSafeZoneInterface.h"
#include "FortTypes.h"
#include "FortMissionStormShield.generated.h"

class AFortMissionStormSafeZone;
class UEnvQuery;
class UFortStormShieldComponent;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneComponent;
class UStaticMeshComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormShieldReachedTargetLocation, FVector, Location);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormShieldReachedTargetRadius, float, Radius);

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FStormShieldMoveData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="StormShieldMoveData")
	float MoveRate;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldMoveData")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldMoveData")
	FVector StartingLocation;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldMoveData")
	float SafeAreaStartLocationChangeTime;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldMoveData")
	float SafeAreaFinishLocationChangeTime;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FStormShieldRadiusGrowthData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="StormShieldRadiusGrowthData")
	float TargetRadius;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldRadiusGrowthData")
	float StartingRadius;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldRadiusGrowthData")
	float GrowthRate;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldRadiusGrowthData")
	float SafeAreaStartRadiusChangeTime;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldRadiusGrowthData")
	float SafeAreaFinishRadiusChangeTime;

	UPROPERTY(BlueprintReadOnly, Category="StormShieldRadiusGrowthData")
	EMissionStormShieldState State;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortMissionStormShield : public AActor, public IFortSafeZoneInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void DestroyStormShield();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void InitializeRadiusValue(const float InRadius);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Storm Shield")
	virtual bool IsInStormShield(FVector TestLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	virtual void PauseStormShield();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void SetTargetLocationToMoveTo(const FVector InTargetLocation, const float InMoveRate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void SetTargetRadiusSizeChangeOverGrowthRate(const float InTargetRadius, const float InGrowthRate, bool bUseGrowthRateDirectly = false);

protected:
	UFUNCTION(BlueprintPure, Category="Storm Shield")
	void GetSafeZones(TArray<AFortMissionStormSafeZone*>& OutSafeZones);

	UFUNCTION()
	void OnRep_RadiusGrowthData();

	UFUNCTION()
	void OnRep_ReplicatedRadius();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	bool RemoveAndDestroySafeArea(AFortMissionStormSafeZone* AreaToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void SetCurrentPhase(const int32 InCurrentPhase);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void SetNumPhases(const int32 InNumPhases);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	void SetRadiusOfShield(const float InRadius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Storm Shield")
	AFortMissionStormSafeZone* SpawnSafeAreaAtLocation(const FVector& InLocation, const float InRadius);

	UFUNCTION(BlueprintNativeEvent, Category="Storm Shield")
	void UpdateRadiusVisuals();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Storm Shield", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Storm Shield", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ShieldRing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	TArray<TSubclassOf<UGameplayEffect>> SafeFromStormPlayerEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	TArray<TSubclassOf<UGameplayEffect>> InStormPlayerEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	TArray<TSubclassOf<UGameplayEffect>> SafeFromStormEnemyEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	TArray<TSubclassOf<UGameplayEffect>> InStormEnemyEffects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Storm Shield")
	float MapWorldScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ReplicatedRadius, Category="Storm Shield")
	float ReplicatedRadius;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RadiusGrowthData, Category="Storm Shield")
	FStormShieldRadiusGrowthData RadiusGrowthData;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Storm Shield")
	FStormShieldMoveData MoveData;

	UPROPERTY(Replicated)
	bool UseGrowthRateDirectly;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Storm Shield")
	bool bAntiStormShield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	float RadiusToWorldScaleConversion;

	UPROPERTY(BlueprintAssignable, Category="Storm Shield")
	FOnStormShieldReachedTargetRadius OnStormShieldReachedRadius;

	UPROPERTY(BlueprintAssignable, Category="Storm Shield")
	FOnStormShieldReachedTargetLocation OnStormShieldReachedLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Storm Shield")
	TSubclassOf<AFortMissionStormSafeZone> SafeAreaTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Storm Shield")
	TObjectPtr<UEnvQuery> StormShieldQuery;

	UPROPERTY(BlueprintReadOnly, Category="Storm Shield")
	float CurrentLocalRadius;

	UPROPERTY(EditDefaultsOnly, Category="Mini map")
	TObjectPtr<UMaterialInterface> StormMiniMapMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> StormMiniMapMaterialMID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mini map")
	FSlateBrush StormMiniMapMaterialBrush;

	UPROPERTY(EditDefaultsOnly, Category="Main map")
	TObjectPtr<UMaterialInterface> StormMainMapMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> StormMainMapMaterialMID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Main map")
	FSlateBrush StormMainMapMaterialBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm Shield")
	bool bRegisterWithGameState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Storm Shield")
	float AutoHideRadius;

private:
	UPROPERTY(Replicated)
	int32 NumPhases;

	UPROPERTY(Replicated)
	int32 CurrentPhase;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AFortMissionStormSafeZone>> SafeAreas;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortStormShieldComponent>> StormShieldComponents;

};

