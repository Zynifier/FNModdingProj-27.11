// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortItemAndCount.h"
#include "STW/Player/FortPlayerControllerPvE.h"
#include "FortPlayerControllerDeployableBase.generated.h"

class ADeployableBasePlot;
enum class EFortCompletionResult : uint8;

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerDeployableBase : public AFortPlayerControllerPvE
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientOnHordeTierComplete(EFortCompletionResult Result);

	UFUNCTION(Client, Reliable)
	void ClientOnHordeTierInitialized(const TArray<FItemAndCount>& Items);

	UFUNCTION(Client, Reliable)
	void ClientOnHordeWaveComplete(const int32 Wave, const TArray<FItemAndCount>& Rewards);

	UFUNCTION(BlueprintCallable, Category="Deployable Base")
	void MoveAllItemsFromDeployableBase();

	UFUNCTION(BlueprintCallable, Category="Deployable Base")
	void MoveAllItemsToDeployableBase();

	UFUNCTION(BlueprintCallable, Category="Deployable Base")
	void MoveItemFromDeployableBase(const FGuid& ItemOnPlot, const int32 Count);

	UFUNCTION(BlueprintCallable, Category="Deployable Base")
	void MoveItemToDeployableBase(const FGuid& ItemOnPlayer, const int32 Count);

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveAllItemsFromDeployableBase(const ADeployableBasePlot* ExpectedPlot);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveAllItemsToDeployableBase(const ADeployableBasePlot* ExpectedPlot);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveItemFromDeployableBase(const FGuid& ItemOnPlot, const int32 Count, const ADeployableBasePlot* ExpectedPlot);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveItemToDeployableBase(const FGuid& ItemOnPlayer, const int32 Count, const ADeployableBasePlot* ExpectedPlot);

	UPROPERTY(Transient)
	TObjectPtr<ADeployableBasePlot> CurrentPlot;

	UPROPERTY(Transient)
	TObjectPtr<ADeployableBasePlot> PreviousPlot;

};

