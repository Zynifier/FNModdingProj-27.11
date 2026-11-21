// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortAnnouncementWidget.generated.h"

class AFortClientAnnouncement;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortAnnouncementWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement", meta=(UnsafeDuringActorConstruction="true"))
	void AnnouncementStopped(AFortClientAnnouncement* Announcement);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement", meta=(UnsafeDuringActorConstruction="true"))
	void BindUpdateEvents(AFortClientAnnouncement* Announcement);

	UFUNCTION(BlueprintCallable)
	FName FindFirstUnboundAction(FText AnnouncementBody);

	UFUNCTION(BlueprintPure)
	FText GetTextForAction(const FName& ActionName) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement", meta=(UnsafeDuringActorConstruction="true"))
	void UpdateWidgetData(AFortClientAnnouncement* Announcement);

protected:
	UPROPERTY(BlueprintReadOnly, Category="Announcement")
	TObjectPtr<AFortClientAnnouncement> BoundAnnouncement;

};

