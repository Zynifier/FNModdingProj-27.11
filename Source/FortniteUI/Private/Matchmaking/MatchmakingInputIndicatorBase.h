// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "CommonUserWidget.h"
#include "GameFramework/OnlineReplStructs.h"
#include "MatchmakingInputIndicatorBase.generated.h"

class USizeBox;

UENUM()
enum class EMatchmakingInputSource : uint8
{
	/** This gets the current input source the local player is using. */
	Local = 0,
	/** This gets the current or locked in 'ready' input source the remote player is using. */
	Remote = 1,
	/** The final input pool the players will be in, based on locked in, or expected pool depending on what they're doing locally before locking in. */
	Pool = 2,
};

UCLASS()
class UMatchmakingInputIndicatorBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetRemotePlayer(FUniqueNetIdRepl UniqueId);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInputSourceTypeChanged(ECommonInputType InputType);

	UPROPERTY(EditAnywhere, Category="MatchmakingInputIndicatorBase")
	EMatchmakingInputSource InputSource;

	UPROPERTY(EditAnywhere, Category="MatchmakingInputIndicatorBase")
	bool bShowLocalInputOnlyWhenDifferentFromDefault;

	UPROPERTY(EditAnywhere, Category="MatchmakingInputIndicatorBase")
	bool bShowRemoteInputOnlyWhenDifferentFromDefault;

	UPROPERTY(Transient)
	FUniqueNetIdRepl RemotePlayerUniqueId;

	UPROPERTY(Transient)
	ECommonInputType LastInputType;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_HotfixVisibility;

};

