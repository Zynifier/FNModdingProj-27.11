// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Party/PartyTypes.h"
#include "UObject/NoExportTypes.h"
#include "FortSupervisedSettingsManager.generated.h"

class UFortLocalPlayer;
enum class ESocialCommsPermission : uint8;
enum class EVoiceChatRecordingPreference : uint8;

UENUM()
enum class ERatingsBoard : uint8
{
	ESRB = 0,
	PEGI = 1,
	USK = 2,
	GRAC = 3,
	IARC = 4,
	ACB = 5,
	ClassInd = 6,
	Russia = 7,
	CERO = 8,
	FPB = 9,
	GCAM = 10,
	MRO = 11,
	None = 12,
};

UENUM(BlueprintType)
enum class ESupervisedSettingRestrictionReason : uint8
{
	ParentalLimit = 0,
	EnforcedLimit = 1,
	None = 2,
};

UENUM()
enum class EVoiceChatRecordingPreference : uint8
{
	PreferRecording = 0,
	PreferNotRecording = 1,
};

UCLASS()
class UFortSupervisedSettingsManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	bool GetAllowCreativeExperiences() const;

	UFUNCTION()
	bool GetCanDisplayMyUserName() const;

	UFUNCTION()
	bool GetCanSeeOtherPlayersNames() const;

	UFUNCTION()
	bool GetFilterMatureLanguage() const;

	UFUNCTION()
	EPartyType GetPartyJoinabilityLimit() const;

	UFUNCTION()
	bool GetPlayerSurveysAllowed() const;

	UFUNCTION()
	FString GetPlaytimeReportingFrequency() const;

	UFUNCTION()
	bool GetPRMExperienceAllowed() const;

	UFUNCTION()
	bool GetPRMFunctionalAllowed() const;

	UFUNCTION()
	bool GetPRMMarketingAllowed() const;

	UFUNCTION()
	bool GetRequirePinToAddFriend() const;

	UFUNCTION()
	bool GetShowSeasonalLevelInFeedLimit() const;

	UFUNCTION()
	ESocialCommsPermission GetTextChatSettings() const;

	UFUNCTION()
	ESocialCommsPermission GetTextChatSettingsLimit() const;

	UFUNCTION()
	virtual FString GetUserGeneratedContentViewable() const;

	UFUNCTION()
	EVoiceChatRecordingPreference GetVoiceChatRecordingPreference() const;

	UFUNCTION()
	ESocialCommsPermission GetVoiceChatSettings() const;

	UFUNCTION()
	ESocialCommsPermission GetVoiceChatSettingsLimit() const;

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortLocalPlayer> OwningPlayer;

};

