// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/MemberReference.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "Creative/FortCreativeIconOption.h"
#include "FortMatchmakingKnobsDataSource.h"
#include "FortUserOptionDefinitions.generated.h"

class UDataTable;
class UObject;
class UPlaylistUserOptions;
class UUserWidget;

UENUM()
enum class EUserOptionDefinitionGenerationFlags : uint8
{
	None = 0,
	AutoAdded = 1,
	Inherited = 2,
};

USTRUCT()
struct FUserOptionCategoryTagPreset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="OptionCategory")
	FString CategoryName;

	UPROPERTY(EditAnywhere, Category="OptionCategory")
	FGameplayTagContainer CategoryTags;

};

USTRUCT()
struct FUserOptionPropertyReference
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMemberReference PropertyRef;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(MustImplement="/Script/FortniteGame.FortPlayerCustomizable"))
	TSoftClassPtr<UObject> PropertyScope;

	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition")
	FUserOptionPropertyReference PropertyReference;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(EditCondition="bOverrideDisplayName"))
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(EditCondition="bOverrideDescription"))
	FText Description;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(Categories="Creative.Property"))
	FGameplayTagContainer ImplicitCategoryTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(Categories="Creative.Property"))
	FGameplayTagContainer AdditionalCategoryTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(Categories="Creative"))
	FGameplayTagQuery RequiredContextTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptionDefinition", meta=(Categories="SharedSettings"))
	FScalableFloat SharedSettingOverride;

	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition", meta=(BaseStruct="/Script/FortniteGame.UserOptionDefinitionMetaData", ExcludeBaseStruct))
	FInstancedStruct MetaData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition")
	TEnumAsByte<UFortMatchmakingKnobsDataSource::Type> MenuListType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition")
	TSubclassOf<UUserWidget> EditWidget;

	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition")
	bool bRequireExplicitOverride;

	UPROPERTY(VisibleDefaultsOnly, Category="OptionDefinition")
	bool bDefaultOverrideValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionDefinition", meta=(EditCondition="bRequireExplicitOverride"))
	FText ExplicitOverrideDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition", meta=(Categories="Creative", EditCondition="bRequireExplicitOverride"))
	FGameplayTagContainer GrantedContextTagsWhenNotOverriden;

	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition")
	FDataTableRowHandle DestructiveAction;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition", meta=(InlineEditConditionToggle))
	bool bOverrideDisplayName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition", meta=(InlineEditConditionToggle))
	bool bOverrideDescription;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	EUserOptionDefinitionGenerationFlags GenerationFlags;
#endif

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionBoolMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bDefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText TrueDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTagsWhenTrue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText FalseDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTagsWhenFalse;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionColorValueEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FLinearColor Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionColorMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FLinearColor DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.UserOptionDefinitionColorValueEntry"))
	TObjectPtr<UDataTable> ValuesDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(EditCondition="ValuesDataTable == nullptr", EditConditionHides))
	TArray<FUserOptionDefinitionColorValueEntry> ValueEntries;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionEnumValueEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FString Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(EditCondition="bOverrideDisplayName"))
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bIsHidden;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

	UPROPERTY(EditDefaultsOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FCreativeIconOption OptionalDisplayIcon;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="OptionMetaData", meta=(InlineEditConditionToggle))
	bool bOverrideDisplayName;
#endif

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionEnumMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FString DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(TitleProperty="DisplayName"))
	TArray<FUserOptionDefinitionEnumValueEntry> ValueEntries;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FDataRegistryType RegistryType;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionEventDescriptorMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionEventFunctionMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionFloatValueEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	float Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionFloatMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	float DefaultValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	float MinValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	float MaxValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	float MinSliderValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	float MaxSliderValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(ClampMin="0.01"))
	float DeltaValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="OptionMetaData", meta=(ClampMax="6", ClampMin="0"))
	uint8 MinFractionalDigits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="OptionMetaData", meta=(ClampMax="6", ClampMin="0"))
	uint8 MaxFractionalDigits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayPattern;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bRestrictSliderValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bUseNumericInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(TitleProperty="DisplayName"))
	TArray<FUserOptionDefinitionFloatValueEntry> ValueEntries;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionIntValueEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionIntMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 DefaultValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MinValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MaxValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MinSliderValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MaxSliderValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(ClampMin="1"))
	int32 DeltaValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayPattern;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bRestrictSliderValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bUseNumericInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(TitleProperty="DisplayName"))
	TArray<FUserOptionDefinitionIntValueEntry> ValueEntries;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FDataRegistryType RegistryType;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionObjectInstanceMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionStringMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FString DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 ValueLengthLimit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bLocalizeValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bSanitizeValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bValidatePersistentID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bAllowLineBreaks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bAllowStyleEditing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FString AllowedCharacters;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTagsIfNotEmpty;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionTextMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 ValueLengthLimit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bSanitizeValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bValidatePersistentID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bAllowLineBreaks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	bool bAllowStyleEditing;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bIsArrayProperty;
#endif

};

USTRUCT(BlueprintType)
struct FUserOptionMigrateLegacyDataConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bForceCreateDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateOptionsContainerData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateCategoryTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateContextTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateMenuListType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateEditWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateRequireExplicitOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateValueRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UserOptions|MigrateLegacyData")
	bool bMigrateValueData;

};

USTRUCT()
struct FUserOptionSharedSetting
{
	GENERATED_BODY()

};

USTRUCT()
struct FUserOptionSharedSettingContainer
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UUserOptionDefinitionContainerInterface : public UInterface
{
	GENERATED_BODY()
};

class IUserOptionDefinitionContainerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions")
	virtual void GetGrantedContextTagsFromObject(const UObject* Object, FGameplayTagContainer& ContextTags) const;

	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions")
	virtual TArray<FUserOptionDefinition> GetUserOptionDefinitions() const;

	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions", meta=(AdvancedDisplay="bAllowGenerated"))
	virtual const UPlaylistUserOptions* GetUserOptionList(const bool bAllowGenerated = true) const;

	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions")
	virtual FText GetUserOptionsDescription() const;

	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions")
	virtual FText GetUserOptionsDisplayName() const;

	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions")
	virtual FCurveTableRowHandle GetUserOptionsInteractionSpeed() const;

	UFUNCTION(BlueprintCallable, Category="UserOptionDefinitions")
	virtual FText GetUserOptionsInteractionText() const;

};

UCLASS(Config=Engine, DefaultConfig, MinimalAPI, meta=(DisplayName="User Option Definitions"))
class UUserOptionDefinitionSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Editor")
	TArray<TSoftClassPtr<UObject>> ClassesWithExplicitUserOptions;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Editor")
	TArray<FUserOptionCategoryTagPreset> UserOptionCategoryTagPresets;
#endif

};

