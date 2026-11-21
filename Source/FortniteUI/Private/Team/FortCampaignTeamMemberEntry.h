// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortTeamMemberEntryBase.h"
#include "FortCampaignTeamMemberEntry.generated.h"

enum class EFortMemberConnectionState : uint8;

UENUM(BlueprintType)
enum class EFortMemberConnectionState : uint8
{
	Open = 0,
	Connecting = 1,
	Connected = 2,
	Invalid = 3,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignTeamMemberEntry : public UFortTeamMemberEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasTeamMembers() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamMemberConnectionStateChanged(EFortMemberConnectionState NewConnectionState);

private:
	UPROPERTY(EditAnywhere, Category="FortCampaignTeamMemberEntry")
	int32 RepresentedMemberIndex;

	UPROPERTY()
	EFortMemberConnectionState CurrentConnectionState;

};

