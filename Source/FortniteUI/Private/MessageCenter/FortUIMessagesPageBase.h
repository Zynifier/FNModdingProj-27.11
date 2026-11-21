// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortUIMessagesPageBase.generated.h"

class UCommonListView;
class UFortUINotification;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortUIMessagesPageBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortUIMessagesPageBase")
	void FillMessagesList();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIMessagesPageBase")
	int32 MaximumMessagesShown;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIMessagesPageBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> MessagesList;

private:
	UFUNCTION()
	void OnMessageAvailable();

	UFUNCTION()
	void OnNotificationCleared(UFortUINotification* ClearedMessage);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortUINotification>> MessagesShown;

};

