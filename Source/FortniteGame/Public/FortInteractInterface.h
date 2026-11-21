// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifyQueue.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortInteractInterface.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerPawn;
class UAnimSequenceBase;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UTexture2D;

UENUM(BlueprintType)
enum EInteractionBeingAttempted
{
	FirstInteraction = 0,
	SecondInteraction = 1,
	AllInteraction = 2,
};

UENUM(BlueprintType)
enum TInteractionType
{
	IT_NoInteraction = 0,
	// Tap

	IT_Simple = 1,
	// Hold

	IT_LongPress = 2,
	// Building edit mode

	IT_BuildingEdit = 3,
	// Building upgrade mode

	IT_BuildingImprovement = 4,
	// Trap placement

	IT_TrapPlacement = 5,
};

USTRUCT(BlueprintType)
struct FInteractionType
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<TInteractionType> InteractionType;

	UPROPERTY()
	TEnumAsByte<EInteractionBeingAttempted> InteractionBeingAttempted;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerPawn> RequestingPawn;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerController> RequestingPlayerController;

	UPROPERTY(Export)
	TWeakObjectPtr<UPrimitiveComponent> InteractComponent;

	UPROPERTY()
	TWeakObjectPtr<UObject> OptionalObjectData;

	UPROPERTY()
	FVector InteractPoint;

};

UINTERFACE(MinimalAPI, BlueprintType)
class UFortInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="InteractInterface")
	AActor* GetActorForInteraction() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void GetBoundsComponents(const AActor* SelfActor, TArray<USceneComponent*>& OutComponents) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void GetConnectedInteractableActors(const AActor* ViewingActor, TArray<AActor*>& OutConnectedActors) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	AActor* GetConnectedVisibleActor() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	TSoftObjectPtr<UTexture2D> GetCustomIcon() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	FLinearColor GetCustomTint() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	FVector GetFocusedSocketLocation() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void GetIconPlacement(const AActor* SelfActor, const AActor* ViewingActor, FVector& OutLocation, FVector& OutExtents) const;

	UFUNCTION(BlueprintNativeEvent)
	float GetMinDistanceFromInteraction() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	bool IconPlacementNeedsUpdate() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void LocalOnFailedInteract(const AFortPlayerPawn* InteractingPawn) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void OnFortInteractAnimNotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, FName NotifyStateName, float TotalDuration, const FAnimNotifyEventReference& EventReference);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void OnFortInteractAnimNotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, FName NotifyStateName, const FAnimNotifyEventReference& EventReference);

	UFUNCTION()
	virtual bool ServerOnAttemptInteract(const FInteractionType& InteractType);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InteractInterface")
	void SetActorForInteraction(const AActor* ForwardInteractionActor);

};

UCLASS(BlueprintType)
class UInteractionTypeContext : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TInteractionType GetInteractionType() const;

private:
	UPROPERTY()
	FInteractionType InteractionType;

};

