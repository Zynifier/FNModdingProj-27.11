// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AudioShapeComponent.h"
#include "AudioShapePrimitiveComponent.generated.h"

class UAudioComponent;
class USoundBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAudioShapeInsideStateChanged, bool, bIsInside);

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("AudioShapes"), meta=(BlueprintSpawnableComponent))
class AUDIOSHAPES_API UAudioShapePrimitiveComponent : public UAudioShapeComponent
{
	GENERATED_BODY()

public:
	/** Valid only if we're within audible range of the shape and if we've internally created the component */
	UFUNCTION(BlueprintPure, Category="Control")
	UAudioComponent* GetEdgeAudioComponent();

	/** Valid only if we're inside the shape and if we've internally created the component */
	UFUNCTION(BlueprintPure, Category="Control")
	UAudioComponent* GetInsideAudioComponent();

	UFUNCTION(BlueprintPure, Category="Control")
	bool GetIsPlayerInside() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Assets")
	TObjectPtr<USoundBase> SoundOnEdge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Assets")
	TObjectPtr<USoundBase> SoundOnInside;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnAudioShapeInsideStateChanged OnInsideStateChanged;

	/** Initialize shape based on the owning actor's transform */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	bool bUseOwningActorTransform;

	/** Refresh the shape from the owning actors transform when needed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	bool bAutoRefreshShape;

	/** Scalar to tweak audio shape bounds if initializing from the actor's transform */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	FVector ActorTransformScale;

};

