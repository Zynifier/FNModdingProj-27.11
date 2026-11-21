// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "Announcement/FortClientAnnouncement.h"
#include "Announcement/FortClientAnnouncement_TutorialInterface.h"
#include "FortClientAnnouncement_Tutorial.generated.h"

USTRUCT(BlueprintType)
struct FFortClientAnnouncementData_Tutorial : public FFortClientAnnouncementData_Basic
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	float AutoContinueDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	FText NameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	FText SystemText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	bool bButtonEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	bool bLightboxEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	bool bLightboxDisableInputOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	FMargin Padding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	TEnumAsByte<EVerticalAlignment> VAlign;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	TEnumAsByte<EHorizontalAlignment> HAlign;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_Tutorial : public AFortClientAnnouncement, public IFortClientAnnouncement_TutorialInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_TutorialData, Category="Announcement|TutorialData", meta=(ExposeOnSpawn="TRUE"))
	FFortClientAnnouncementData_Tutorial TutorialData;

protected:
	UFUNCTION()
	void OnRep_TutorialData(const FFortClientAnnouncementData_Tutorial& PreviousTutorialData);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement|Tutorial")
	float AutoContinueDelay;

};

