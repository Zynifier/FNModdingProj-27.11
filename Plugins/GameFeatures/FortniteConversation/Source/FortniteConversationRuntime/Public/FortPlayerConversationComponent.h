// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortGiftUINotifications.h"
#include "FortConversationParticipantComponent.h"
#include "FortPlayerConversationComponent.generated.h"

class AFortPawn;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class AFortWeapon;
class UFortNonPlayerConversationParticipantComponent;

UENUM(BlueprintType)
enum class EInteractionRange : uint8
{
	Preview = 0,
	Interaction = 1,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class FORTNITECONVERSATIONRUNTIME_API UFortPlayerConversationComponent : public UFortConversationParticipantComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientReceiveConversationGiftUINotification(const FGiftUINotificationInfo& ConversationGiftUINotification);

	UFUNCTION(Client, Reliable)
	void ClientSpectatorCloseUI();

	UFUNCTION(Client, Reliable)
	void ClientSpectatorEnterConversationState();

	UFUNCTION(Client, Reliable)
	void ClientSpectatorLeaveConversationState();

	UFUNCTION(Client, Reliable)
	void ClientSpectatorOpenUI();

	UFUNCTION(Server, Reliable)
	void RequestServerAbortConversation();

	UFUNCTION(Server, Reliable)
	void RequestServerAbortConversationWithParticipant(const UFortNonPlayerConversationParticipantComponent* Participant);

private:
	UFUNCTION()
	void HandleDBNOChanged(AFortPawn* Pawn, bool bIsDBNO);

	UFUNCTION()
	void HandleFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatingPC, AFortPlayerState* FollowedPlayerState);

	UFUNCTION()
	void HandleViewTargetChanged();

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNonPlayerConversationParticipantComponent>> ConversationParticipantsInRange;

	UPROPERTY(EditAnywhere, Category="Conversation")
	float GreetSphereRadius;

	UPROPERTY(EditAnywhere, Category="Conversation")
	float IconVisibilityRadius;

	UPROPERTY(EditAnywhere, Category="Conversation")
	float AbortConversationRange;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	FGameplayTag RidingOnActorTag;

	UPROPERTY(EditAnywhere, Category="Conversation")
	float RidingOnActorRangeMultiplierSquared;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TSet<TObjectPtr<UFortNonPlayerConversationParticipantComponent>> IndicatedNPCConversationComponents;

	UPROPERTY(Config)
	bool bMoveShouldAbortConversation;

};

