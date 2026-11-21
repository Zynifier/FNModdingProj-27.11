// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/UpdateLevelVisibilityLevelInfo.h"
#include "Misc/DateTime.h"
#include "OnlineBeaconClient.h"
#include "MeshBeaconClient.generated.h"

UCLASS()
class MESHNETWORK_API AMeshBeaconClient : public AOnlineBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetClientId(const FString& NewClientId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateLevelVisibility(const FUpdateLevelVisibilityLevelInfo& LevelVisibility);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateMultipleLevelsVisibility(const TArray<FUpdateLevelVisibilityLevelInfo>& LevelVisibilities);

protected:
	UFUNCTION()
	void OnRep_ConnectedToRoot();

	UFUNCTION()
	virtual void OnRep_MeshPingTime();

	UFUNCTION()
	void OnRep_ParentIds();

	UPROPERTY(ReplicatedUsing=OnRep_ConnectedToRoot)
	bool bConnectedToRoot;

	UPROPERTY(ReplicatedUsing=OnRep_MeshPingTime)
	FDateTime MeshPingTime;

	UPROPERTY(ReplicatedUsing=OnRep_ParentIds)
	TArray<FString> ParentIds;

	UPROPERTY()
	FString ClientId;

};

