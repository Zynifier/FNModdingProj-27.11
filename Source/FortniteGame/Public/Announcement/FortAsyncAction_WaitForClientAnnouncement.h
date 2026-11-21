// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/Guid.h"
#include "FortAsyncAction_WaitForClientAnnouncement.generated.h"

class AFortClientAnnouncement;
class UFortAsyncAction_WaitForClientAnnouncement;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortAllClientsReady);

UCLASS()
class UFortAsyncAction_WaitForClientAnnouncement : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Announcement", meta=(BlueprintInternalUseOnly="true", HidePin="WorldContextObject", WorldContext="InWorldContextObject"))
	static UFortAsyncAction_WaitForClientAnnouncement* WaitForClientAnnouncement(UObject* InWorldContextObject, AFortClientAnnouncement* AnnouncementToWaitFor);

	UPROPERTY(BlueprintAssignable)
	FFortAllClientsReady OnAllClientsReady;

	UPROPERTY(BlueprintAssignable)
	FFortAllClientsReady OnCanceled;

private:
	UPROPERTY(Transient)
	FGuid AnnouncementId;

	UPROPERTY()
	FTimerHandle CheckAllPlayersReadyTimerHandle;

};

