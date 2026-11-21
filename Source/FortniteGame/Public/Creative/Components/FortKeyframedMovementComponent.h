// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortKeyframedMovementComponent.generated.h"

class ABuildingActor;
class UFortNavModifierComponent;
enum class EFortKeyframedMovementMovementMode : uint8;

UENUM(BlueprintType)
enum class EFortKeyframedMovementMovementMode : uint8
{
	EFKMMM_OneShot = 0 UMETA(DisplayName="OneShot"),
	EFKMMM_Loop = 1 UMETA(DisplayName="Loop"),
	EFKMMM_PingPong = 2 UMETA(DisplayName="Ping Pong"),
};

UENUM()
enum class EFortKeyframedMovementNetCommand : uint8
{
	EFKMNC_PlayFrom = 0,
	EFKMNC_HaltAt = 1,
};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortKeyframedMovementKeyframeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortKeyframedMovementKeyframeData")
	FTransform Transform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortKeyframedMovementKeyframeData")
	FVector4 CubicBezierEasingParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortKeyframedMovementKeyframeData")
	float Time;

};

USTRUCT()
struct FFortKeyframedMovementCommandData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortKeyframedMovementNetCommand Command;

	UPROPERTY()
	float CommandServerTime;

	UPROPERTY()
	float StartTimeForPlay;

	UPROPERTY()
	FTransform HaltTransform;

	UPROPERTY()
	TArray<FFortKeyframedMovementKeyframeData> Keyframes;

	UPROPERTY()
	EFortKeyframedMovementMovementMode MovementMode;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortKeyframedMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnKeyframedMovementCompleteSignatureBlueprint, UFortKeyframedMovementComponent, OnKeyframedMovementCompleteBlueprintDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnKeyframedMovementKeyframeReachedSignatureBlueprint, UFortKeyframedMovementComponent, OnKeyframedMovementKeyframeReachedBlueprintDelegate, int64, KeyframeNumber, bool, InReverse);

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool HasValidAnimation() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsPaused() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsPlaying() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void MoveTo(const FTransform& TargetTransform, float OverTime);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Pause();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Play();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool SetKeyframes(const TArray<FFortKeyframedMovementKeyframeData>& RelativeKeyframes, EFortKeyframedMovementMovementMode MovementModeIn = EFortKeyframedMovementMovementMode::EFKMMM_OneShot, bool NotifyStateChangeListeners = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Stop();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TeleportTo(const FTransform& Transform);

	UPROPERTY(BlueprintAssignable)
	FOnKeyframedMovementKeyframeReachedSignatureBlueprint OnKeyframedMovementKeyframeReachedBlueprintDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnKeyframedMovementCompleteSignatureBlueprint OnKeyframedMovementCompleteBlueprintDelegate;

private:
	UFUNCTION()
	void OnRep_CommandState();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortNavModifierComponent> CachedNavModifierComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CommandState)
	FFortKeyframedMovementCommandData PendingCommand;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> Target;

};

