// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Styling/SlateBrush.h"
#include "FortCreativeItemData.h"
#include "FortDialogTypes.generated.h"

class UFortNotificationHandler;
class USoundBase;
class UUserWidget;
class UWidget;

UENUM(BlueprintType)
enum class EFortDialogFeedbackType : uint8
{
	FriendRequestSent = 0,
	FriendRequestReceived = 1,
	FriendRequestAccepted = 2,
	Default = 3,
};

UENUM(BlueprintType)
enum class EFortDialogResult : uint8
{
	/** The "yes" button was pressed */
	Confirmed = 0,
	/** The "no" button was pressed */
	Declined = 1,
	/** The "ignore/cancel" button was pressed */
	Ignored = 2,
	/** The dialog was explicitly killed (no user input) */
	Killed = 3,
	/** The dialog timed out */
	TimedOut = 4,
	Unknown = 5 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FConfirmationDialogAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConfimationDialogAction")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConfimationDialogAction")
	FName ResultName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConfimationDialogAction")
	FSlateBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ConfimationDialogAction")
	FName ActionName;

};

USTRUCT(BlueprintType)
struct FFortCreativeOptionDestructiveAction : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeOptionDestructiveAction")
	ECreativeOptionDestructiveActionOperator CheckedActionOperator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeOptionDestructiveAction")
	FText DialogTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeOptionDestructiveAction")
	FText DialogInfoText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeOptionDestructiveAction")
	FName ConfirmActionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeOptionDestructiveAction")
	TArray<FConfirmationDialogAction> ButtonInputActions;

};

USTRUCT(BlueprintType)
struct FFortDialogDescription
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FSlateBrush Icon;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText MessageHeader;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText MessageBody;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText AcceptButtonText;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText IgnoreButtonText;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText DismissButtonText;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	float DisplayTime;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortDialog", meta=(EditInline="true"))
	TObjectPtr<UUserWidget> AdditionalContent;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	EFortDialogFeedbackType FeedBackType;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	bool Dismissable;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	TObjectPtr<UFortNotificationHandler> NotificationHandler;

};

USTRUCT(BlueprintType)
struct FFortDialogDescription_NUI
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FSlateBrush Icon;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText MessageHeader;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FText MessageBody;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	TArray<FConfirmationDialogAction> ConfirmButtonInputActions;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	FName DeclineButtonInputAction;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortDialog", meta=(EditInline="true"))
	TObjectPtr<UWidget> AdditionalContent;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortDialog", meta=(EditInline="true"))
	TObjectPtr<UWidget> LeftAdditionalContent;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	float DisplayTime;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	bool Dismissable;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	bool Cancelable;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	bool bCloseOnEsc;

	UPROPERTY(BlueprintReadOnly, Category="FortDialog")
	bool bShouldWaitForLatentActionOnConfirmAction;

	UPROPERTY(BlueprintReadWrite, Category="FortDialog")
	TObjectPtr<UFortNotificationHandler> NotificationHandler;

	UPROPERTY(BlueprintReadOnly, Category="FortDialog")
	TObjectPtr<USoundBase> ShowSound;

};

USTRUCT(BlueprintType)
struct FFortDialogExternalLatentActionHandle
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 Handle;

};

