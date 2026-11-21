// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/Guid.h"
#include "Styling/SlateBrush.h"
#include "FortClientEventInterface.h"
#include "FortClientAnnouncement.generated.h"

class AFortClientAnnouncement;
class AFortPlayerController;
class USoundBase;
class UUserWidget;

UENUM(BlueprintType)
enum class EFortAnnouncementChannel : uint8
{
	Primary = 0,
	// Primary announcement, runs in the center top UI

	Conversation = 1,
	// Conversation announcement, affects talking head UI. Merge this channel with primary to stop them from happening simultaneously

	Tutorial = 2,
	// Onboarding/Tutorial announcement, runs with the tutorial widget

	Max_None = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortAnnouncementDelivery : uint8
{
	Created = 0,
	// The announcement has been created and will soon be sent	

	Received = 1,
	// The announcement has been received on the client and is waiting to activate

	Ignored = 2,
	// The announcement has been received on the client but it is not designated for this client, so it is ignored.

	Active = 3,
	// The announcement is currently active and interacting with the client

	Stopped = 4,
	// The announcement has been stopped on the client

	Max_None = 5 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortAnnouncementDisplayPreference : uint8
{
	Default_HUD = 0,
	QuestIntroduction = 1,
	QuestJournal = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewClientAnnouncementOnClientDelegate, AFortClientAnnouncement*, NewAnnouncement);

USTRUCT(BlueprintType)
struct FFortClientAnnouncementData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortClientAnnouncementData_Basic : public FFortClientAnnouncementData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	FSlateBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	FText TitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	FText DetailText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	FText GamepadDetailText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	float DisplayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Basic")
	TObjectPtr<USoundBase> OnStartSound;

};

UCLASS(Abstract, NotPlaceable, MinimalAPI, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement : public AActor, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Announcement", meta=(UnsafeDuringActorConstruction="true"))
	void CancelClientAnnouncement();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement", meta=(UnsafeDuringActorConstruction="true"))
	int32 GetPriority();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void StopClientAnnouncement();

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Announcement")
	FGuid AnnouncementID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement")
	TSubclassOf<UUserWidget> DisplayWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement", meta=(ExposeOnSpawn="TRUE"))
	float TimeToLive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement", meta=(ExposeOnSpawn="TRUE"))
	bool bRetrigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement", meta=(ExposeOnSpawn="TRUE"))
	bool bDestroyOnAllClientsStopped;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement")
	EFortAnnouncementChannel Channel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Announcement", meta=(ExposeOnSpawn="TRUE"))
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Announcement", meta=(ExposeOnSpawn="TRUE"))
	bool bInterrupt;

	UPROPERTY(BlueprintReadOnly, Category="Announcement")
	EFortAnnouncementDelivery ClientDeliveryStatus;

	UPROPERTY(BlueprintReadOnly, Category="Announcement")
	float ClientDeliveryTime;

	UPROPERTY(BlueprintAssignable, Category="Announcement")
	FOnNewClientAnnouncementOnClientDelegate OnUpdateAnnouncementData;

	UPROPERTY(BlueprintAssignable, Category="Announcement")
	FOnNewClientAnnouncementOnClientDelegate OnAnnouncementStopped;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement")
	void OnClientAnnouncementStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement")
	void OnClientAnnouncementStop();

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Announcement", meta=(BlueprintProtected="TRUE", ExposeOnSpawn="TRUE"))
	TArray<TObjectPtr<AFortPlayerController>> RecipientControllers;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_Basic : public AFortClientAnnouncement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Basic", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetDetailText(FText DetailText);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Basic", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetDisplayTime(float DisplayTime);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Basic", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetIcon(FSlateBrush& Icon);

	UFUNCTION(BlueprintAuthorityOnly, Category="Announcement|Basic", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	virtual void SetTitleText(FText TitleText);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_BasicData, Category="AnnouncementData", meta=(ExposeOnSpawn="TRUE"))
	FFortClientAnnouncementData_Basic BasicData;

protected:
	UFUNCTION()
	void OnRep_BasicData(const FFortClientAnnouncementData_Basic& PreviousBasicData);

};

