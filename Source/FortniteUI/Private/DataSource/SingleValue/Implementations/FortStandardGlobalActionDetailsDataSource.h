// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataSource/SingleValue/FortGlobalActionDetailsDataSource.h"
#include "FortGlobals.h"
#include "FortStandardGlobalActionDetailsDataSource.generated.h"

class AFortPlayerController;
class UCommonInputSubsystem;
class UFortGlobalUIContext;
class UFortStandardGlobalActionDetailsDataSource;
class UObject;
class UWidget;
enum class EFortGlobalAction : uint8;

UCLASS(BlueprintType)
class UFortStandardGlobalActionDetailsDataSource : public UObject, public IFortGlobalActionDetailsDataSource
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortNameDataSourceOnChangeInternalDelegate, UObject*, Source);

public:
	UFUNCTION(BlueprintCallable, Category="Global Action Details", meta=(AutoCreateRefTerm="ActionDetailsContext", DisplayName="Construct FortStandardGlobalActionDetailsDataSource"))
	static UFortStandardGlobalActionDetailsDataSource* Construct(UObject* Outer, UFortGlobalUIContext* GlobalUIContext, UCommonInputSubsystem* CommonInputSubsystem, EFortGlobalAction GlobalAction, const FFortGlobalActionDetailsFunctionContext& ActionDetailsContext);

	UFUNCTION(BlueprintCallable, Category="Global Action Details", meta=(AutoCreateRefTerm="ActionDetailsContext", DisplayName="Construct FortStandardGlobalActionDetailsDataSource (with default contexts)"))
	static UFortStandardGlobalActionDetailsDataSource* ConstructWithDefaultContexts(UObject* Outer, UWidget* ContextWidget, EFortGlobalAction GlobalAction, const FFortGlobalActionDetailsFunctionContext& ActionDetailsContext);

	UFUNCTION(BlueprintCallable, Category="Global Action Details")
	void SetActionDetailsContext(const FFortGlobalActionDetailsFunctionContext& Value);

	UFUNCTION(BlueprintCallable, Category="Global Action Details")
	void SetCommonInputSubsystem(UCommonInputSubsystem* Value);

	UFUNCTION(BlueprintCallable, Category="Global Action Details")
	void SetGlobalAction(EFortGlobalAction Value);

	UFUNCTION(BlueprintCallable, Category="Global Action Details")
	void SetGlobalUIContext(UFortGlobalUIContext* Value);

protected:
	UFUNCTION()
	void HandlePlayerControllerChanged(UObject* Source);

	UPROPERTY()
	TObjectPtr<UFortGlobalUIContext> GlobalUIContext;

	UPROPERTY()
	TObjectPtr<UCommonInputSubsystem> CommonInputSubsystem;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerController> FortPlayerController;

	UPROPERTY()
	FFortGlobalActionDetailsFunctionContext ActionDetailsContext;

};

