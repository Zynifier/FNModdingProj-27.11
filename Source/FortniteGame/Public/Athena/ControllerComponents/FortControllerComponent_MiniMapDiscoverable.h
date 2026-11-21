// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/UI/FortMiniMapComponent_Discoverable.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_MiniMapDiscoverable.generated.h"

class AFortPlayerStateAthena;
class UFortControllerComponent_MiniMapDiscoverable;
class UFortMiniMapComponent_Discoverable;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FControllerComponentMiniMapDiscoverableUIDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllerComponentMiniMapDiscoverableVisibilitiesMapUpdated, const UFortControllerComponent_MiniMapDiscoverable*, ControllerComponentMiniMapDiscoverable);

USTRUCT()
struct FFortControllerMiniMapComponentVisibility : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMiniMapComponent_Discoverable> MiniMapComponent;

	UPROPERTY()
	EMiniMapComponentDiscoverableVisibility Visibility;

};

USTRUCT()
struct FFortControllerMiniMapComponentVisibilitiesArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortControllerMiniMapComponentVisibility> Entries;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MiniMapDiscoverable : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientSendOnSquadAlliesSharedMiniMapVisibilityMessage();

	UPROPERTY(BlueprintAssignable)
	FControllerComponentMiniMapDiscoverableUIDelegate OnSquadAlliesSharedMiniMapVisibility;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentMiniMapDiscoverableVisibilitiesMapUpdated OnClientVisibilitiesMapUpdated;

private:
	UFUNCTION()
	void HandleServerSquadChange(AFortPlayerStateAthena* InPlayerstate, const uint8 PreviousSquadId);

	UFUNCTION()
	void OnRep_FortControllerMiniMapComponentVisibilities();

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MiniMapDiscoverable", meta=(AllowPrivateAccess))
	FScalableFloat bShareMiniMapComponentVisibilityWithAllySquadmates;

	UPROPERTY(ReplicatedUsing=OnRep_FortControllerMiniMapComponentVisibilities)
	FFortControllerMiniMapComponentVisibilitiesArray FortControllerMiniMapComponentVisibilities;

	UPROPERTY()
	TMap<TObjectPtr<UFortMiniMapComponent_Discoverable>, FFortControllerMiniMapComponentVisibility> FortControllerMiniMapComponentVisibilitiesMap;

};

