// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/CraftingObjectComponent.h"
#include "Components/FortControllerComponent.h"
#include "Types/CraftingTypes.h"
#include "FortControllerComponent_CraftingNetworkEvents.generated.h"

class AActor;
class AFortPickup;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_CraftingNetworkEvents : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Unreliable)
	void ClientNotifyCraftingFailed(AActor* CraftingObject, const FGameplayTagContainer& FailedReason, FCraftingMultiKey Key);

	UFUNCTION(Client, Reliable)
	void ClientNotifyCraftingSuccess(AActor* CraftingObject, const FName& FormulaRowName, FCraftingMultiKey Key);

	UFUNCTION()
	void NotifyCraftingSuccess(AActor* CraftingObject, const FName& FormulaRowName, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_Key="()"))
	void ServerCancelCrafting(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_Key="()"))
	void ServerClaimCraftingResults(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerEjectItems(AActor* CraftingObject);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_Key="()"))
	void ServerPauseCrafting(AActor* CraftingObject, bool bDecayPausedTime, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_Key="()"))
	void ServerPickupItemAndStartCrafting(AActor* CraftingObject, AFortPickup* Pickup, const FName& CraftingFormulaName, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_Key="()"))
	void ServerReportCraftingSuccess(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_Key="()"))
	void ServerResumeCrafting(AActor* CraftingObject, FCraftingMultiKey Key);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, meta=(CPP_Default_NumberToCraft="1", CPP_Default_Key="()"))
	void ServerStartCrafting(AActor* CraftingObject, const FName& CraftingFormulaName, const int32 NumberToCraft, FCraftingMultiKey Key);

	UPROPERTY(BlueprintAssignable)
	FCraftingObjectOnCraftingSuccess OnCraftingSuccess;

};

