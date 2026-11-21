// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Athena/MeshNetworkEvents/FortMeshNetworkEventsSubsystem.h"
#include "PlayspaceComponent.h"
#include "FortPlayspaceComponent.generated.h"

enum class EMeshNetworkNodeType : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayspaceComponent : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventBurst(const FName& EventName, const EMeshNetworkNodeType NodeType, const FString& EventParameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventChange(const FName& EventName, const FDateTime& EventStartTime, const EMeshNetworkNodeType NodeType, const FString& EventParameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventEnd(const FName& EventName, const EMeshNetworkNodeType NodeType);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventStart(const FName& EventName, const FDateTime& EventStartTime, const EMeshNetworkNodeType NodeType, const FString& EventParameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkReady(EMeshNetworkNodeType NodeType);

protected:
	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkReady OnMeshNetworkReady_BP;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventBurst OnMeshNetworkEventBurst_BP;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventStart OnMeshNetworkEventStart_BP;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventChange OnMeshNetworkEventChange_BP;

	UPROPERTY(BlueprintAssignable)
	FOnMeshNetworkEventEnd OnMeshNetworkEventEnd_BP;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspaceComponent")
	bool bSubscribeToMeshNetwork;

};

