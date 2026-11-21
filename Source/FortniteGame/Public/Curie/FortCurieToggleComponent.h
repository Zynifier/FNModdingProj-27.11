// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "CurieMinimalTypes.h"
#include "FortCurieToggleComponent.generated.h"

class UObject;

UENUM(BlueprintType)
enum class EFortCurieToggleComponentActivationBehavior : uint8
{
	/** Activate only if any of the valid application elements apply and then attach to the specified material component; Implies deactivation behavior tied to lifespan of element  */
	OnValidAttachment = 0,
};

UENUM(BlueprintType)
enum class EFortCurieToggleComponentDeactivationBehavior : uint8
{
	/** Never deactivate the component after activation */
	NeverDeactivate = 0,
	/** Deactivate the component after DeactivationTime seconds, refreshing the timer if a new application comes in */
	TimedDeactivationAllowRefresh = 1,
	/** Deactivate the component after DeactivationTime seconds, not allowing it to be refreshed by subsequent applications */
	TimedDeactivationNoRefresh = 2,
};

UCLASS(HideCategories=("Collision", "Object", "Tags"), ClassGroup=("Curie"), meta=(BlueprintSpawnableComponent))
class UFortCurieToggleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Curie")
	void OnActive();

	UFUNCTION(BlueprintNativeEvent, Category="Curie")
	void OnInactive();

protected:
	UFUNCTION()
	virtual void OnElementApplied(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag ElementIdentifier);

	UFUNCTION()
	virtual void OnElementAttached(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag ElementIdentifier);

	UFUNCTION()
	virtual void OnElementDetached(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag ElementIdentifier);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behavior", meta=(Categories="Curie.Element"))
	FGameplayTagContainer ActivationElements;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behavior")
	EFortCurieToggleComponentActivationBehavior ActivationBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behavior", meta=(EditCondition="ActivationBehavior != EFortCurieToggleComponentActivationBehavior::OnValidAttachment"))
	EFortCurieToggleComponentDeactivationBehavior DeactivationBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behavior", meta=(EditCondition="ActivationBehavior != EFortCurieToggleComponentActivationBehavior::OnValidAttachment && DeactivationBehavior != EFortCurieToggleComponentDeactivationBehavior::NeverDeactivate"))
	float DeactivationTime;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ToggleGroup", meta=(Categories="Curie.ToggleGroup"))
	FGameplayTag ToggleGroup;

	UPROPERTY(Transient)
	FTimerHandle TimedDeactivationHandle;

};

