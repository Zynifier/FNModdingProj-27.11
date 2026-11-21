// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Party/PartyTypes.h"
#include "Components/FortControllerComponent.h"
#include "PartyRiftEmotesPlayerComponent.generated.h"

class AFortAthenaMutator_PartyRiftEmotes;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UPartyRiftEmotesPlayerComponent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientSendSpawnAnalytics(const FVector Location, const int32 DeploymentTime, const FString& Reason) const;

protected:
	UFUNCTION()
	void OnRep_MutatorPartyRiftEmotes();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetOwnerAsPartyLeader(const bool bPartyLeader);

	UPROPERTY(ReplicatedUsing=OnRep_MutatorPartyRiftEmotes)
	TObjectPtr<AFortAthenaMutator_PartyRiftEmotes> MutatorPartyRiftEmotes;

	UPROPERTY(EditDefaultsOnly, Category="PartyRiftEmotesPlayerComponent")
	float LongRangeInteractionTimer;

private:
	UFUNCTION()
	void HandlePrivacySettingsChanged(const FPartyPrivacySettings& NewPrivacySettings);

	UFUNCTION(Server, Reliable)
	void Server_SetOwnerAway(const bool bNewValue);

	UFUNCTION(Server, Reliable)
	void Server_SetPartyFull(const bool bNewValue);

	UFUNCTION(Server, Reliable)
	void Server_SetPartyPrivacy(const EPartyType NewPartyPrivacy);

	UFUNCTION(Server, Reliable)
	void Server_SetRequestToJoinPrivateIntention(const bool bNewIntention);

	UPROPERTY(Replicated)
	bool bIsOwnerPartyLeader;

};

