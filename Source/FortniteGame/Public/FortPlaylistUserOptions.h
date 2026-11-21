// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "Engine/CollisionProfile.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "Framework/Text/CharRangeList.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "UObject/PrimaryAssetId.h"
#include "UObject/SoftObjectPath.h"
#include "Creative/CreativeEditablePropertyInterface.h"
#include "Creative/FortCreativeClassOption.h"
#include "Creative/FortCreativeIconOption.h"
#include "Creative/FortCreativeStatOption.h"
#include "Creative/FortCreativeTeamOption.h"
#include "Creative/FortCreativeToyOptionInterface.h"
#include "FortCreativeItemData.h"
#include "FortMatchmakingKnobsDataSource.h"
#include "FortUserOptionProviderInterface.h"
#include "FortPlaylistUserOptions.generated.h"

class UDataTable;
class UMaterial;
class UObject;
class UPlaylistUserOptionBase;
class UPlaylistUserOptionsFilter;
class UTexture2D;
class UUserWidget;

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FPlaylistOptionValue : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionValue")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionValue")
	FString OptionValueName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionValue", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

	UPROPERTY(EditDefaultsOnly, Category="PlaylistOptionValue", meta=(Categories="Creative"))
	FCreativeIconOption OptionalDisplayIcon;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionCollisionProfileValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionCollisionProfileValue")
	FCollisionProfileName Value;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionColorValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionColorValue")
	FLinearColor Value;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionFloatValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionFloatValue")
	FScalableFloat Value;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionIconValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionIconValue")
	FCreativeIconOption Value;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FPlaylistOptionIntValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionIntValue")
	int32 Value;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionLevelValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionLevelValue")
	FGuid LevelInstanceGuid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionLevelValue")
	FString LevelName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionLevelValue")
	bool bNewLevel;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionSoftObjectValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionSoftObjectValue")
	FSoftObjectPath Value;

};

USTRUCT(BlueprintType)
struct FPlaylistOptionTintedIconIntValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionTintedIconIntValue")
	FLinearColor Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionTintedIconIntValue")
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionTintedIconIntValue")
	int32 SecondaryValue;

};

USTRUCT(BlueprintType)
struct FPlaylistUserOptionClassTypeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassTypeEntry")
	ECreativeClassType Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassTypeEntry")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassTypeEntry", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FPlaylistUserOptionTeamTypeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamTypeEntry")
	ECreativeTeamType Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamTypeEntry")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamTypeEntry", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

UCLASS(MinimalAPI, BlueprintType)
class UColorOptionObjectWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ColorOptionObjectWrapper")
	FPlaylistOptionTintedIconIntValue ColorOption;

};

UCLASS(MinimalAPI)
class UFortUserOptionProxy : public UObject, public IFortUserOptionProvider, public ICreativeEditablePropertyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptionBase> ItemOption;

	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptionsFilter> OptionFilter;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> SubItems;

	UPROPERTY(Transient)
	TObjectPtr<UObject> InitializingObject;

};

UCLASS(MinimalAPI, BlueprintType)
class UIconOptionObjectWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IconOptionObjectWrapper")
	FPlaylistOptionIconValue IconOption;

};

UCLASS(MinimalAPI, BlueprintType)
class ULevelOptionObjectWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LevelOptionObjectWrapper")
	FPlaylistOptionLevelValue LevelOption;

};

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UPlaylistUserOptionBase : public UDataAsset, public IFortUserOptionProvider, public IFortCreativeToyOptionInterface, public ICreativeEditablePropertyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FString GetOptionKey(bool bWithScoping = false, const UPlaylistUserOptionsFilter* Filter = nullptr) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FString GetOptionValueNameFromValue(const FString& OptionValue, bool bAllowNoOverride = true, const UPlaylistUserOptionsFilter* Filter = nullptr) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	FText OptionDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	FText OptionDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(Categories="Creative"))
	FGameplayTagQuery RequiredContextTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(Categories="SharedSettings"))
	FScalableFloat SharedSettingOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(Categories="Creative"))
	bool bTestRequiredContextAgainstGameState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	TObjectPtr<UMaterial> OptionMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	bool bCanHaveNoOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(EditCondition="bCanHaveNoOverride"))
	bool bDefaultOverrideValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(Categories="Creative", EditCondition="bCanHaveNoOverride"))
	FText NoOverrideDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(Categories="Creative", EditCondition="bCanHaveNoOverride"))
	FGameplayTagContainer GrantedContextTagsWhenNoOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	TEnumAsByte<UFortMatchmakingKnobsDataSource::Type> MenuListType;

	UPROPERTY(EditDefaultsOnly, Category="OptionDefinition")
	FDataTableRowHandle DestructiveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	bool bCheckDestructiveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(Categories="Creative", EditCondition="bCheckDestructiveAction"))
	ECreativeOptionDestructiveActionOperator DestructiveActionOperator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	TObjectPtr<UPlaylistUserOptionBase> OverridenBy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	FDataRegistryType RegistryType;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase", meta=(MustImplement="/Script/FortniteGame.FortPlayerCustomizable"))
	TSoftClassPtr<UObject> OptionScope;

	UPROPERTY(EditDefaultsOnly, Category="PlaylistUserOptionBase")
	FString OptionKey;

	UPROPERTY(Transient)
	FString OverridePrimaryAssetName;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	int32 WeightOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBase")
	TSubclassOf<UUserWidget> EditWidget;

};

UCLASS(Abstract, MinimalAPI)
class UPlaylistUserDualDataOptionBase : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FString GetSecondaryOptionKey(bool bWithScoping = false, const UPlaylistUserOptionsFilter* Filter = nullptr) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="PlaylistUserDualDataOptionBase")
	FString SecondaryOptionKey;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserIconEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserIconEnum")
	TArray<FPlaylistOptionIconValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserIconEnum")
	int32 DefaultValueIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionBool : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBool")
	bool bDefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBool")
	FText OptionOnText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBool", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTagsWhenOn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBool")
	FText OptionOffText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionBool", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTagsWhenOff;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionClassSlot : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassSlot")
	FCreativeClassOption DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassSlot")
	int32 MinClassSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassSlot")
	int32 MaxClassSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassSlot")
	FText ClassSlotDisplayPattern;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionClassSlot")
	TArray<FPlaylistUserOptionClassTypeEntry> ClassTypeEntries;

};

UCLASS(BlueprintType)
class UPlaylistUserOptionCollisionProfileEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionCollisionProfileEnum")
	TArray<FPlaylistOptionCollisionProfileValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionCollisionProfileEnum")
	int32 DefaultValueIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionColorEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionColorEnum")
	TArray<FPlaylistOptionColorValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionColorEnum")
	bool bExplicitDefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionColorEnum", meta=(EditCondition="!bExplicitDefaultValue"))
	int32 DefaultValueIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionColorEnum", meta=(EditCondition="bExplicitDefaultValue"))
	FPlaylistOptionColorValue DefaultValue;

};

UCLASS(Config=Game, BlueprintType)
class UPlaylistUserOptionConfigIntRange : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionConfigIntRange")
	int32 Min;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionConfigIntRange")
	int32 Max;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionConfigIntRange")
	FString MaxValueCVarName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionConfigIntRange")
	int32 DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionConfigIntRange")
	int32 IncrementValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionConfigIntRange")
	int32 Shift;

	UPROPERTY()
	TMap<int32, FText> OverrideValueStrings_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="PlaylistUserOptionConfigIntRange")
	TArray<FPlaylistOptionIntValue> OverrideOptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionConfigIntRange")
	FText OptionPrefix;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UPlaylistUserOptionEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionEnum")
	TArray<FPlaylistOptionValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionEnum")
	int32 DefaultValueIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionEventDescriptor : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionEventFunction : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UPlaylistUserOptionFloatEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatEnum")
	TArray<FPlaylistOptionFloatValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatEnum")
	int32 DefaultValueIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionFloatRange : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetSliderMax() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetSliderMin() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatRange")
	float Min;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatRange")
	float Max;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetSliderMin, AdvancedDisplay, Category="PlaylistUserOptionFloatRange", meta=(EditCondition="bOverrideSliderRange"))
	float SliderMin;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetSliderMax, AdvancedDisplay, Category="PlaylistUserOptionFloatRange", meta=(EditCondition="bOverrideSliderRange"))
	float SliderMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatRange")
	float DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatRange", meta=(ClampMin="0.01"))
	float IncrementValue;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="PlaylistUserOptionFloatRange")
	bool bOverrideSliderRange;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="PlaylistUserOptionFloatRange")
	bool bRestrictSliderValues;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="PlaylistUserOptionFloatRange")
	bool bUseNumericInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="PlaylistUserOptionFloatRange", meta=(ClampMax="6", ClampMin="0"))
	uint8 MinFractionalDigits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="PlaylistUserOptionFloatRange", meta=(ClampMax="6", ClampMin="0"))
	uint8 MaxFractionalDigits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFloatRange")
	FText UnitName;

	UPROPERTY()
	TMap<float, FText> OverrideValueStrings_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="PlaylistUserOptionFloatRange")
	TArray<FPlaylistOptionFloatValue> SliderOptionValues;

	UPROPERTY()
	int32 SliderOptionValues_DefaultIndex;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UPlaylistUserOptionIntEnum : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntEnum")
	TArray<FPlaylistOptionIntValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntEnum")
	int32 DefaultValueIndex;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UPlaylistUserOptionIntRange : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	int32 GetSliderMax() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	int32 GetSliderMin() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntRange")
	int32 Min;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntRange")
	int32 Max;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetSliderMin, AdvancedDisplay, Category="PlaylistUserOptionIntRange", meta=(EditCondition="bOverrideSliderRange"))
	int32 SliderMin;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetSliderMax, AdvancedDisplay, Category="PlaylistUserOptionIntRange", meta=(EditCondition="bOverrideSliderRange"))
	int32 SliderMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntRange")
	int32 DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntRange", meta=(ClampMin="1"))
	int32 IncrementValue;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="PlaylistUserOptionIntRange")
	bool bOverrideSliderRange;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="PlaylistUserOptionIntRange")
	bool bRestrictSliderValues;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="PlaylistUserOptionIntRange")
	bool bUseNumericInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionIntRange")
	FText UnitName;

	UPROPERTY()
	TMap<int32, FText> OverrideValueStrings_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="PlaylistUserOptionIntRange")
	TArray<FPlaylistOptionIntValue> SliderOptionValues;

	UPROPERTY()
	int32 SliderOptionValues_DefaultIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionMusicTrackDataTable : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionMusicTrackDataTable")
	TObjectPtr<UDataTable> DataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionMusicTrackDataTable")
	FString DefaultValue;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionObjectInstance : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UPlaylistUserOptionPrimaryAsset : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionPrimaryAsset")
	TArray<FPrimaryAssetId> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionPrimaryAsset")
	int32 DefaultValueIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionSoftActorReference : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UPlaylistUserOptionSoftObjectReference : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionSoftObjectReference")
	TArray<FPlaylistOptionSoftObjectValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionSoftObjectReference")
	int32 DefaultValueIndex;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionString : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	int32 EntryCharLimit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	bool bAllowLineBreaks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	bool bAllowStyleEditing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	FString DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	bool bCanBeLocalized;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	bool bShouldBeSanitized;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString")
	bool bShouldValidatePersistentID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionString", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTagsIfNotEmpty;

	UPROPERTY(EditDefaultsOnly, Category="PlaylistUserOptionString")
	FCharRangeList AllowedCharacters;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionTeamIndex : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamIndex")
	FCreativeTeamOption DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamIndex")
	int32 MinTeamIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamIndex")
	int32 MaxTeamIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamIndex")
	FText TeamIndexDisplayPattern;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTeamIndex")
	TArray<FPlaylistUserOptionTeamTypeEntry> TeamTypeEntries;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionTrackedStat : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTrackedStat")
	TArray<FCreativeStatOption> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTrackedStat")
	int32 DefaultValueIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionTrackedStat")
	bool bIncludePlayerDefined;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptions : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptions")
	bool bSupportNoOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptions")
	TArray<TObjectPtr<UPlaylistUserOptionBase>> Options;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptions")
	TArray<TSubclassOf<UPlaylistUserOptionsFilter>> OptionFilters;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UPlaylistUserOptionsFilter : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool IsValueFiltered(const FString& Value) const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionsFilter")
	TObjectPtr<UPlaylistUserOptionBase> KnobThatWeAreBeingApplied;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionsFilter")
	TArray<FString> ValuesToIgnore;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionsFilter")
	FString OverridenOptionKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionsFilter")
	FText OverridenOptionDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionsFilter")
	FText OverridenOptionDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlaylistUserOptionsFilter")
	FString OverridenDefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionsFilter", meta=(Categories="Creative", EditCondition="bOverrideRequiredContextTagQuery"))
	FGameplayTagQuery OverridenRequiredContextTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="PlaylistUserOptionsFilter", meta=(InlineEditConditionToggle))
	bool bOverrideRequiredContextTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionsFilter")
	bool bInvertIgnoredValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionsFilter")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionsFilter")
	TEnumAsByte<UFortMatchmakingKnobsDataSource::Type> MenuListType;

};

UCLASS(MinimalAPI)
class UPlaylistUserOptionsFilterRange : public UPlaylistUserOptionsFilter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionsFilterRange")
	FIntPoint RangeToPreserve;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserTintedIconIntEnum : public UPlaylistUserDualDataOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserTintedIconIntEnum")
	TArray<FPlaylistOptionTintedIconIntValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserTintedIconIntEnum")
	int32 DefaultValueIndex;

};

