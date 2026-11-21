// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayComponent.h"
#include "Interfaces/IAudioGameplayCondition.h"
#include "AudioShapeComponent.generated.h"

class APlayerController;
class UAudioComponent;

// Enum describing the audio shape state.  Active shapes can be configured to update at a faster rate than inactive ones

UENUM(BlueprintType)
enum class EAudioShapeComponentState : uint8
{
	// Shape is outside of audible range of any valid listeners

	Inactive = 0,
	// Shape is within audible range of a valid listener

	Active = 1,
	Count = 2 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAudioShapeAudibleStateChanged, bool, bIsAudible);

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("AudioShapes"), meta=(BlueprintSpawnableComponent))
class AUDIOSHAPES_API UAudioShapeComponent : public UAudioGameplayComponent, public IAudioGameplayCondition
{
	GENERATED_BODY()

public:
	/**
	 *  Updates this component - called from AudioShapeManager
	 */
	UFUNCTION()
	void UpdateAudioShape(const TArray<APlayerController*>& InLocalControllers);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Update Rate", meta=(ClampMin="0.0"))
	float MaxDistanceOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Update Rate", meta=(ClampMin="0.0"))
	float SmoothingDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Shape", meta=(ClampMin="0.0"))
	float FadeInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio Shape", meta=(ClampMin="0.0"))
	float FadeOutTime;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnAudioShapeAudibleStateChanged OnAudibleStateChanged;

protected:
	UFUNCTION(BlueprintCallable, Category="Shape")
	virtual void Disable();

	//~ Begin UAudioGameplayComponent Interface

	UFUNCTION(BlueprintCallable, Category="Shape")
	virtual void Enable();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UAudioComponent>> AudioComponents;

	UPROPERTY(Transient)
	TArray<TObjectPtr<APlayerController>> LocalControllers;

};

