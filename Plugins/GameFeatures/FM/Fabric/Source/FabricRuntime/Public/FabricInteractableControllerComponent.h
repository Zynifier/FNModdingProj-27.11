// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FabricInteractableControllerComponent.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerPawn;
class UFortGadgetItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNoInteractablesHit);

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FABRICRUNTIME_API UFabricInteractableControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EnsurePlayerHasInteractionTool();

	UFUNCTION(BlueprintCallable)
	void GiveBackInteractionTool();

	UFUNCTION()
	void OnCreativeModeEnabledChangedDelegate(bool bCreativeEnabled);

	UFUNCTION(Server, Reliable)
	void ServerGivePlayerFabricInteractionTool();

	UPROPERTY(BlueprintAssignable)
	FOnNoInteractablesHit OnNoInteractablesHit;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricInteractableControllerComponent")
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(EditDefaultsOnly, Category="FabricInteractableControllerComponent", meta=(DisplayName="Fabric Interaction Tool Item Definition"))
	TSoftObjectPtr<UFortGadgetItemDefinition> FabricInteractionToolItemDefSoftPtr;

	UPROPERTY(Transient)
	TObjectPtr<UFortGadgetItemDefinition> FabricInteractionToolItemDef;

private:
	UFUNCTION(Client, Reliable)
	void ClientReceiveDoesIslandContainFabricDevices(const bool bIslandContainsFabricDevices);

	UFUNCTION(Server, Reliable)
	void ServerRequestDoesIslandContainFabricDevices();

	UPROPERTY(EditDefaultsOnly, Category="FabricInteractableControllerComponent")
	TSoftClassPtr<AActor> SoftFabricDeviceBaseClass;

};

