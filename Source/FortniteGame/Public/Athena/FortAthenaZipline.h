// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "FortAthenaZipline.generated.h"

class AActor;
class AFortPlayerPawn;
class AFortWaterBodyActor;
class UCapsuleComponent;
class UPrimitiveComponent;

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaZiplineBase : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, meta=(ReturnDisplayName="Was Overridden"))
	FORTNITEGAME_API bool AttempOverrideLaunch(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, const bool bJumped, const bool bReachedEnd, const FVector& CurrentVelocity) const;

	UFUNCTION(BlueprintNativeEvent, meta=(ReturnDisplayName="Was Overridden"))
	FORTNITEGAME_API bool AttemptOverrideZiplineSocketOffset(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, const FVector& BaseSocketOffset, FVector& OutSocketOffset) const;

	UFUNCTION(BlueprintNativeEvent, meta=(ReturnDisplayName="Can Begin"))
	FORTNITEGAME_API bool CanBeginZiplining(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent) const;

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void HandleActorHitWhileMoving(AFortPlayerPawn* InteractingPawn, AActor* HitActor, bool& bOutIsHitActorImmobile) const;

	UFUNCTION(BlueprintNativeEvent, meta=(ReturnDisplayName="Is Variable Speed Enabled"))
	FORTNITEGAME_API bool IsVariableSpeedEnabled(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent) const;

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnZipliningStarted(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnZipliningStopped(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, float ZiplineUsageDuration);

	UFUNCTION(BlueprintNativeEvent, meta=(ReturnDisplayName="Should Ignore"))
	FORTNITEGAME_API bool ShouldIgnoreWaterBody(AFortPlayerPawn* InteractingPawn, AFortWaterBodyActor* WaterBody) const;

	UFUNCTION(BlueprintNativeEvent, meta=(ReturnDisplayName="Should Override"))
	FORTNITEGAME_API bool ShouldOverrideVelocityDirection(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent, float& OutVelocityDirection) const;

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void AuthorityForceEndZiplining(AFortPlayerPawn* PawnToStop);

	UFUNCTION(BlueprintPure, Category="Zipline")
	FORTNITEGAME_API bool UseInteractToEnterZipline() const;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> CachedInteractContextPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zipline")
	FGameplayTag EnterZiplineTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zipline")
	FGameplayTag ExitZiplineTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zipline")
	FScalableFloat ExitZiplineRemoveFromIgnoreWhenMovingTimeDelay;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaZipline : public AFortAthenaZiplineBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Zipline")
	FORTNITEGAME_API void Initialize(const FVector& NewStartPosition, const FVector& NewEndPosition);

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineVariableSpeedEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat DownhillAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat UphillAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat DownhillDeceleration;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat UphillDeceleration;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineDownhillSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineUphillSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineUphillSpeedMin;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineEntryOffset;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineExitOffset;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Zipline")
	FVector StartPosition;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Zipline")
	FVector EndPosition;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Zipline")
	bool bInitialized;

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortAthenaZipline")
	TWeakObjectPtr<UCapsuleComponent> InteractIconPlacementCapsule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Zipline")
	FScalableFloat DestructionEnabled;

};

