// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/Guid.h"
#include "FortClientAnnouncementManager.generated.h"

class AFortClientAnnouncement;

USTRUCT()
struct FFortClientAnnouncementQueue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<AFortClientAnnouncement>> Announcements;

};

UCLASS(MinimalAPI)
class AFortClientAnnouncementManager : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_CancelledAnnouncements();

	UFUNCTION()
	void OnRep_ClientAnnouncements(TArray<TWeakObjectPtr<AFortClientAnnouncement>>& PreviousClientAnnouncements);

	UPROPERTY(ReplicatedUsing=OnRep_ClientAnnouncements)
	TArray<TWeakObjectPtr<AFortClientAnnouncement>> ClientAnnouncements;

	UPROPERTY()
	TArray<TWeakObjectPtr<AFortClientAnnouncement>> LocalClientAnnouncements;

	UPROPERTY(ReplicatedUsing=OnRep_CancelledAnnouncements)
	TArray<FGuid> CancelledAnnouncements;

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortAnnouncementChannel"))
	FFortClientAnnouncementQueue Channels[3];

};

