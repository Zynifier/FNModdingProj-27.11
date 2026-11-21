// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "FortClientEventInterface.h"
#include "FortEventName.h"
#include "FortScriptedAction.generated.h"

class AFortPlayerController;
class UFortItem;

UENUM(BlueprintType)
enum class EFortScriptedActionEnvironment : uint8
{
	// Only exists in the frontend

	FrontEnd = 0,
	// Exists on the server in game

	GameServer = 1,
	// Exists on the client in game

	GameClient = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EFortScriptedActionSource : uint8
{
	// Tied to a specific quest, which will be in SourceItem. SourceData will be the objective row

	Quest = 0,
	// Granted by a Token item, which is in SourceItem

	Token = 1,
	// Manually added action, called from blueprint to register specific actions

	Manual = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

USTRUCT(BlueprintType)
struct FFortScriptedActionParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortScriptedActionParams")
	TObjectPtr<AFortPlayerController> Player;

	UPROPERTY(BlueprintReadOnly, Category="FortScriptedActionParams")
	EFortScriptedActionSource SourceType;

	UPROPERTY(BlueprintReadOnly, Category="FortScriptedActionParams")
	TObjectPtr<UFortItem> SourceItem;

	UPROPERTY(BlueprintReadOnly, Category="FortScriptedActionParams")
	FDataTableRowHandle SourceData;

	UPROPERTY(BlueprintReadOnly, Category="FortScriptedActionParams")
	FName SourceName;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Actor", "Navigation", "Replication"))
class AFortScriptedAction : public AActor, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ScriptedAction", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	FORTNITEGAME_API void CancelAction(bool bRegisterActionAgain = false);

	UFUNCTION(BlueprintNativeEvent, Category="ScriptedAction")
	FORTNITEGAME_API bool CanExecute(const FFortScriptedActionParams& Params) const;

	UFUNCTION(BlueprintNativeEvent, Category="ScriptedAction")
	FORTNITEGAME_API void Execute(const FFortScriptedActionParams& Params);

	UFUNCTION(BlueprintCallable, Category="ScriptedAction", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	FORTNITEGAME_API void GetParams(FFortScriptedActionParams& Params);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ScriptedAction")
	EFortScriptedActionEnvironment ActionEnvironment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ScriptedAction")
	FFortClientEventName ClientEventTrigger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ScriptedAction")
	int32 ActionPriority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="ScriptedAction")
	bool bAllowOtherActionsWhenActive;

protected:
	UFUNCTION(BlueprintCallable, Category="ScriptedAction", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	FORTNITEGAME_API void CompleteAction(bool bRegisterActionAgain = false);

	UPROPERTY(Transient)
	FFortScriptedActionParams CachedParams;

	UPROPERTY(Transient)
	bool bIsActive;

};

