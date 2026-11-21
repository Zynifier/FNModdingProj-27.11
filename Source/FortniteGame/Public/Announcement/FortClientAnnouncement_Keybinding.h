// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Announcement/FortClientAnnouncement.h"
#include "FortClientAnnouncement_Keybinding.generated.h"

USTRUCT(BlueprintType)
struct FActionTextPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActionTextPair")
	FName Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActionTextPair")
	FText Text;

};

USTRUCT(BlueprintType)
struct FFortClientAnnouncementData_Keybinding : public FFortClientAnnouncementData_Basic
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Keybinding")
	TArray<FActionTextPair> GamapadActionTextList;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_Keybinding : public AFortClientAnnouncement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Keybinding", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void AddGamepadActionTextPair(FActionTextPair Pair);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Keybinding", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void ResetGamepadActionTextPairList();

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Keybinding", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetDetailText(FText DetailText);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Keybinding", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetDisplayTime(float DisplayTime);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Keybinding", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetIcon(FSlateBrush& Icon);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Keybinding", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetTitleText(FText TitleText);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_KeybindingData, Category="Announcement|Keybinding", meta=(ExposeOnSpawn="TRUE"))
	FFortClientAnnouncementData_Keybinding KeybindingData;

protected:
	UFUNCTION()
	void OnRep_KeybindingData(const FFortClientAnnouncementData_Keybinding& PreviousKeybindingData);

};

