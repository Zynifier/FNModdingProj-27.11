// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Squads/AthenaSquadDisplayData.h"
#include "Team/FortBasicTeamMemberEntry.h"
#include "Team/FortTeamMemberEntryBase.h"
#include "AthenaSquadMemberEntry.generated.h"

class UCommonTextBlock;
class UFortSocialAvatarIcon;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaMinimalSquadMemberEntry : public UFortTeamMemberEntryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ReadyIcon;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSquadMemberDetailedEntry : public UFortBasicTeamMemberEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FAthenaTeamDisplayInfo GetSquadDisplayInfo() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadAssigned();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaSquadMemberDetailedEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> AvatarIcon_MemberAvatar;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaSquadMemberDetailedEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ParticipationStatus;

};

