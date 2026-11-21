// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Generators/MovieSceneEasingFunction.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "DaySequenceModifierComponent.generated.h"

class AActor;
class ADaySequenceActor;
class UDaySequence;
class UMaterialInterface;
class UObject;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class EDayNightCycleMode : uint8
{
	/** (default) Make no changes to the day/night cycle time */
	Default = 0,
	/** Force the day/night cycle to be fixed at the specified constant time */
	FixedTime = 1,
	/** Set an initial time for the day/night cycle when this modifier is enabled */
	StartAtSpecifiedTime = 2,
	/** Use a random, fixed time for the day/night cycle */
	RandomFixedTime = 3,
	/** Start the day/night cycle at a random time, and allow it to continue from there */
	RandomStartTime = 4,
};

UENUM(BlueprintType)
enum class EDaySequenceModifierBlendMode : uint8
{
	/** Do not blend into the volume - modifier will immediately active when enabled */
	None = 0,
	/** Blend the modifier in based on the distance within the volume. Only functional when EnableDistanceVolumeBlends is called. */
	Distance = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPostEnableModifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPostReinitializeSubSequences);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVolumeBlendTargetOverlap, AActor*, OverlappingActor);

USTRUCT(BlueprintType)
struct FDaySequenceModifierNamedSequence
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sequence", meta=(AllowedClasses="/Script/DaySequence.DaySequence"))
	TObjectPtr<UDaySequence> Sequence;

	UPROPERTY(EditAnywhere, Category="Sequence")
	int32 BiasOffset;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Physics", "Navigation", "Collision", "HLOD", "Rendering", "Cooking", "Mobile", "RayTracing", "AssetUserData", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UDaySequenceModifierComponent : public USceneComponent, public IMovieSceneEasingFunction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddBoolOverride(UObject* Object, FName PropertyName, bool bValue);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddColorMaterialParameterOverride(UObject* Object, int32 MaterialIndex, FName ParameterName, FLinearColor Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddColorOverride(UObject* Object, FName PropertyName, FLinearColor Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddMaterialOverride(UObject* Object, int32 MaterialIndex, UMaterialInterface* Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddScalarMaterialParameterOverride(UObject* Object, int32 MaterialIndex, FName ParameterName, float Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddScalarOverride(UObject* Object, FName PropertyName, double Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddStaticTimeOfDayOverride(ADaySequenceActor* Actor, float Hours);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddTransformOverride(UObject* Object, FTransform Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddVectorOverride(UObject* Object, FName PropertyName, FVector Value);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void AddVisibilityOverride(UObject* Object, bool bValue);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void BindToDaySequenceActor(ADaySequenceActor* DaySequenceActor);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void DisableComponent();

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void DisableModifier();

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void EnableComponent();

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void EnableDistanceVolumeBlends(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void EnableModifier();

	UFUNCTION(BlueprintPure, Category="Day Sequence")
	float GetCurrentBlendWeight() const;

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	bool IsBlendTargetInAnyVolume();

	UFUNCTION(BlueprintPure, Category="Day Sequence")
	bool IsNamedSequenceMuted(FName SequenceKey) const;

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void MuteNamedSequence(FName SequenceKey, bool bState);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void ResetOverrides();

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void SetCustomVolumeBlendWeight(float Weight);

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void SetUserDaySequence(UDaySequence* InDaySequence);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Day Sequence")
	void SetVolumeCollisionEnabled(const ECollisionEnabled::Type InCollisionType) const;

	UFUNCTION(BlueprintCallable, Category="Day Sequence")
	void UnbindFromDaySequenceActor();

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="Day Sequence")
	TObjectPtr<ADaySequenceActor> TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence", meta=(AllowAnyActor, AllowedClasses="/Script/Engine.ShapeComponent", UseComponentPicker))
	TArray<FComponentReference> VolumeShapeComponents;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ExternalVolumeBlendTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence")
	TObjectPtr<UDaySequence> UserDaySequence;

	UPROPERTY(Transient)
	TObjectPtr<UDaySequence> ProceduralDaySequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence")
	TMap<FName, FDaySequenceModifierNamedSequence> AdditionalNamedDaySequences;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence", meta=(EditCondition="!bIgnoreBias"))
	int32 Bias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Time", meta=(DisplayAfter="DayNightCycle", DisplayName="Time", EditCondition="DayNightCycle==EDayNightCycleMode::FixedTime || DayNightCycle==EDayNightCycleMode::StartAtSpecifiedTime", EditConditionHides))
	float DayNightCycleTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence", meta=(DisplayAfter="BlendMode", EditCondition="BlendMode!=EDaySequenceModifierBlendMode::None", EditConditionHides))
	float BlendAmount;

	UPROPERTY(Transient)
	float CustomVolumeBlendWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Time", meta=(DisplayName="Day/Night Cycle"))
	EDayNightCycleMode DayNightCycle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence")
	EDaySequenceModifierBlendMode BlendMode;

	UPROPERTY(Transient, BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnPostReinitializeSubSequences OnPostReinitializeSubSequences;

	UPROPERTY(Transient, BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnPostEnableModifier OnPostEnableModifier;

	UPROPERTY(Transient, BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnVolumeBlendTargetOverlap OnVolumeBlendTargetOverlapBegin;

	UPROPERTY(Transient, BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnVolumeBlendTargetOverlap OnVolumeBlendTargetOverlapEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence", meta=(InlineEditConditionToggle))
	uint8 bIgnoreBias : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Day Sequence")
	uint8 bUseVolume : 1;

	UPROPERTY(BlueprintReadOnly, Transient, DuplicateTransient, Category="Day Sequence")
	uint8 bIsComponentEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, DuplicateTransient, Category="Day Sequence")
	uint8 bIsEnabled : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Day Sequence")
	uint8 bPreview : 1;

private:
	UFUNCTION()
	void OnVolumeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnVolumeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

