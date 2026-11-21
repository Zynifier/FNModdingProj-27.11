// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Athena/Squads/AthenaSquadDisplayData.h"
#include "AthenaTeamSquadEntry.generated.h"

class UCommonRichTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaTeamSquadEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	int32 GetSquadId() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadAssigned(const FAthenaTeamDisplayInfo& SquadStyle);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadIsEmptyChanged(bool bSquadIsEmpty, bool bMultipleSquadsPopulated);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortTeamMemberEntryBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Members;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTeamSquadDetailedEntry : public UAthenaTeamSquadEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_SquadName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_LockReason;

};

