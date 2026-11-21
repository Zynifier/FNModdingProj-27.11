// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortFeedbackManager.generated.h"

class AController;
class AFortFeedbackManager;
class AFortPawn;
class AFortPawn_FeedbackAnnouncer;
class UAnimMontage;
class UAnimSequence;
class UFortFeedbackBank;
class UObject;
class USoundBase;

UENUM()
enum EFortFeedbackAddressee
{
	// The feedback line is addressing the instigator of the event (only instigator hears)

	FFA_Instigator = 0,
	// The feedback line is addressing the recipient of the event (only recipient hears)

	FFA_Recipient = 1,
	// The feedback line is addressing everyone (everyone hears)

	FFA_All = 2,
};

UENUM(BlueprintType)
enum EFortFeedbackBroadcastFilter
{
	// Play this feedback to the speaker only

	FFBF_Speaker = 0,
	// Play this feedback to the speaker and their team only

	FFBF_SpeakerTeam = 1,
	// Play this feedback to the speaker and the addressee only

	FFBF_SpeakerAdressee = 2,
	// Play this feedback to the human team 1 only

	FFBF_HumanPvP_Team1 = 3,
	// Play this feedback to the human team 2 only

	FFBF_HumanPvP_Team2 = 4,
	// No broadcast filter

	FFBF_None_Max = 5,
};

UENUM()
enum EFortFeedbackContext
{
	// The feedback speaker is the instigator of the action

	FFC_Instigator = 0,
	// The feedback speaker is the recipient of the action

	FFC_Recipient = 1,
	// The feedback speaker is a team member of the Instigator and witnessed the action

	FFC_TeamWitness = 2,
	// The feedback speaker is not a team member of the Instigator and witnessed the action

	FFC_EnemyWitness = 3,
	// All Pawns should try and say something

	FFC_AllPawns = 4,
	// The "announcer" is speaking

	FFC_Announcer = 5,
	FFC_None_Max = 6,
};

UENUM()
enum EFortFeedbackSelectionMethod
{
	// Only try and play the instigator feedback, if possible

	FFSM_Instigator = 0,
	// Only try and play the recipient feedback, if possible

	FFSM_Recipient = 1,
	// Only try and play the team witness feedback, if possible

	FFSM_TeamWitness = 2,
	// Only try and play the enemy witness feedback, if possible

	FFSM_EnemyWitness = 3,
	// Randomly select the appropriate context for the feedback to play

	FFSM_Random = 4,
	// Try and play in the order of priority: Instigator, Recipient, Team Witness, Enemy Witness

	FFSM_Priority_IRTE = 5,
	// All pawns can say something, if possible

	FFSM_AllPawns = 6,
	// The "announcer" has something to say

	FFSM_Announcer = 7,
};

USTRUCT(BlueprintType)
struct FFortFeedbackHandle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	TObjectPtr<UFortFeedbackBank> FeedbackBank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	FName EventName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	bool bReadOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	bool bBankDefined;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	TEnumAsByte<EFortFeedbackBroadcastFilter> BroadcastFilterOverride;

};

USTRUCT()
struct FFortFeedbackResponse
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Feedback")
	FFortFeedbackHandle Handle;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TEnumAsByte<EFortFeedbackContext> Context;

};

USTRUCT()
struct FFortFeedbackLine
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Feedback")
	TSoftObjectPtr<USoundBase> Audio;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TSoftObjectPtr<UAnimSequence> AnimSequence;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TSoftObjectPtr<UAnimMontage> AnimMontage;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TEnumAsByte<EFortFeedbackAddressee> Addressee;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TEnumAsByte<EFortFeedbackContext> Context;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TArray<FFortFeedbackResponse> ResponseEvents;

	UPROPERTY(Transient)
	bool bInterruptCurrentLine;

	UPROPERTY(Transient)
	bool bCanBeInterrupted;

	UPROPERTY(Transient)
	bool bCanQue;

};

USTRUCT()
struct FFortFeedbackAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Feedback")
	FFortFeedbackHandle Handle;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TArray<FFortFeedbackLine> Lines;

};

USTRUCT()
struct FFortFeedbackActionBankDefined : public FFortFeedbackAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Feedback", meta=(DisplayName="Min Replay Time (All Speakers)"))
	float MinReplayTime;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(DisplayName="Min Replay Time (This Speaker)"))
	float MinReplayTimeForSpeaker;

};

USTRUCT()
struct FFortFeedbackEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPawn> Instigator;

	UPROPERTY()
	TObjectPtr<AFortPawn> Recipient;

	UPROPERTY(EditAnywhere, Category="Feedback")
	FFortFeedbackHandle Handle;

	UPROPERTY()
	float Delay;

	UPROPERTY()
	bool bOverriddenQueuing;

};

USTRUCT()
struct FFortFeedbackEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Feedback")
	FFortFeedbackHandle Handle;

	UPROPERTY(EditAnywhere, Category="Feedback")
	float ChanceToPlay;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(DisplayName="Min Replay Time (All Speakers)"))
	float MinReplayTime;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(DisplayName="Min Replay Time (This Speaker)"))
	float MinReplayTimeForSpeaker;

	UPROPERTY(EditAnywhere, Category="Feedback")
	float MaxWitnessDistance;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bInterruptCurrentLine;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bCanBeInterrupted;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bCanQue;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TEnumAsByte<EFortFeedbackBroadcastFilter> MultiplayerBroadcastFilter;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TEnumAsByte<EFortFeedbackSelectionMethod> ContextSelectionMethod;

	UPROPERTY(EditAnywhere, Category="Feedback")
	float FeedbackDelay;

	UPROPERTY(Transient)
	float TimeLastPlayed;

};

USTRUCT()
struct FFortSpokenLine
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<USoundBase> Audio;

	UPROPERTY()
	TObjectPtr<UAnimMontage> AnimMontage;

	UPROPERTY()
	TObjectPtr<UAnimSequence> AnimSequence;

	UPROPERTY()
	TObjectPtr<AFortPawn> Addressee;

	UPROPERTY()
	TEnumAsByte<EFortFeedbackBroadcastFilter> BroadcastFilter;

	UPROPERTY()
	float Delay;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bInterruptCurrentLine;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bCanBeInterrupted;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bCanQue;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation", "Rendering", "Input"))
class AFortFeedbackManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Feedback", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static AFortPawn_FeedbackAnnouncer* GetAnnouncerPawn(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Feedback", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static AFortFeedbackManager* GetFeedbackManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Feedback")
	void SuppressProceduralFeedback(TArray<AController*> ControllersToSuppress);

	UPROPERTY(EditAnywhere, EditFixedSize, Category="Feedback")
	TArray<FFortFeedbackEventData> FeedbackEvents;

	UPROPERTY(EditDefaultsOnly, Category="Feedback")
	bool bUsesStWFeedbackEvents;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TArray<FFortFeedbackEventData> BankDefinedFeedbackEvents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Feedback")
	TSubclassOf<AFortPawn_FeedbackAnnouncer> AnnouncerPawnClass;

protected:
	UPROPERTY(Replicated)
	TObjectPtr<AFortPawn_FeedbackAnnouncer> Announcer;

	UPROPERTY(Replicated)
	TArray<TWeakObjectPtr<AController>> SuppressedControllers;

};

