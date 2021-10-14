// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MathUtilityModule/Public/BlueprintLibrary/MathUtilityLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMathUtilityLibrary() {}
// Cross Module References
	MATHUTILITYMODULE_API UClass* Z_Construct_UClass_UMathUtilityLibrary_NoRegister();
	MATHUTILITYMODULE_API UClass* Z_Construct_UClass_UMathUtilityLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_MathUtilityModule();
// End Cross Module References
	DEFINE_FUNCTION(UMathUtilityLibrary::execMathMapf)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Value);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Omin);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Omax);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Nmin);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Nmax);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ReturnValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMathUtilityLibrary::MathMapf(Z_Param_Out_Value,Z_Param_Out_Omin,Z_Param_Out_Omax,Z_Param_Out_Nmin,Z_Param_Out_Nmax,Z_Param_Out_ReturnValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMathUtilityLibrary::execMathMapi)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Value);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Omin);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Omax);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Nmin);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Nmax);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_ReturnValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMathUtilityLibrary::MathMapi(Z_Param_Out_Value,Z_Param_Out_Omin,Z_Param_Out_Omax,Z_Param_Out_Nmin,Z_Param_Out_Nmax,Z_Param_Out_ReturnValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMathUtilityLibrary::execMathMapd)
	{
		P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_Value);
		P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_Omin);
		P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_Omax);
		P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_Nmin);
		P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_Nmax);
		P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_ReturnValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMathUtilityLibrary::MathMapd(Z_Param_Out_Value,Z_Param_Out_Omin,Z_Param_Out_Omax,Z_Param_Out_Nmin,Z_Param_Out_Nmax,Z_Param_Out_ReturnValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMathUtilityLibrary::execMathMapd_)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Value);
		P_GET_PROPERTY(FStrProperty,Z_Param_Omin);
		P_GET_PROPERTY(FStrProperty,Z_Param_Omax);
		P_GET_PROPERTY(FStrProperty,Z_Param_Nmin);
		P_GET_PROPERTY(FStrProperty,Z_Param_Nmax);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ReturnValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMathUtilityLibrary::MathMapd_(Z_Param_Value,Z_Param_Omin,Z_Param_Omax,Z_Param_Nmin,Z_Param_Nmax,Z_Param_Out_ReturnValue);
		P_NATIVE_END;
	}
	void UMathUtilityLibrary::StaticRegisterNativesUMathUtilityLibrary()
	{
		UClass* Class = UMathUtilityLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MathMapd", &UMathUtilityLibrary::execMathMapd },
			{ "MathMapd_", &UMathUtilityLibrary::execMathMapd_ },
			{ "MathMapf", &UMathUtilityLibrary::execMathMapf },
			{ "MathMapi", &UMathUtilityLibrary::execMathMapi },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics
	{
		struct MathUtilityLibrary_eventMathMapd_Parms
		{
			double Value;
			double Omin;
			double Omax;
			double Nmin;
			double Nmax;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omin_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Omin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omax_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Omax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmin_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Nmin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmax_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Nmax;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omin = { "Omin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd_Parms, Omin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omax = { "Omax", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd_Parms, Omax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmin = { "Nmin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd_Parms, Nmin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmax = { "Nmax", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd_Parms, Nmax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmax_MetaData)) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Omax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_Nmax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::Function_MetaDataParams[] = {
		{ "Category", "MathUtilities" },
		{ "DisplayName", "double Mapping" },
		{ "Keywords", "Mapping" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/MathUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMathUtilityLibrary, nullptr, "MathMapd", nullptr, nullptr, sizeof(MathUtilityLibrary_eventMathMapd_Parms), Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMathUtilityLibrary_MathMapd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics
	{
		struct MathUtilityLibrary_eventMathMapd__Parms
		{
			FString Value;
			FString Omin;
			FString Omax;
			FString Nmin;
			FString Nmax;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omin_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Omin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omax_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Omax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmin_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Nmin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmax_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Nmax;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd__Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omin = { "Omin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd__Parms, Omin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omax = { "Omax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd__Parms, Omax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmin = { "Nmin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd__Parms, Nmin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmax = { "Nmax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd__Parms, Nmax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmax_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapd__Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Omax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_Nmax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::Function_MetaDataParams[] = {
		{ "Category", "MathUtilities" },
		{ "DisplayName", "double_ Mapping" },
		{ "Keywords", "Mapping" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/MathUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMathUtilityLibrary, nullptr, "MathMapd_", nullptr, nullptr, sizeof(MathUtilityLibrary_eventMathMapd__Parms), Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMathUtilityLibrary_MathMapd__Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics
	{
		struct MathUtilityLibrary_eventMathMapf_Parms
		{
			float Value;
			float Omin;
			float Omax;
			float Nmin;
			float Nmax;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Omin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Omax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Nmin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Nmax;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapf_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omin = { "Omin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapf_Parms, Omin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omax = { "Omax", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapf_Parms, Omax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmin = { "Nmin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapf_Parms, Nmin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmax = { "Nmax", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapf_Parms, Nmax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmax_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapf_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Omax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_Nmax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::Function_MetaDataParams[] = {
		{ "Category", "MathUtilities" },
		{ "DisplayName", "float Mapping" },
		{ "Keywords", "Mapping" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/MathUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMathUtilityLibrary, nullptr, "MathMapf", nullptr, nullptr, sizeof(MathUtilityLibrary_eventMathMapf_Parms), Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMathUtilityLibrary_MathMapf()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMathUtilityLibrary_MathMapf_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics
	{
		struct MathUtilityLibrary_eventMathMapi_Parms
		{
			int32 Value;
			int32 Omin;
			int32 Omax;
			int32 Nmin;
			int32 Nmax;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omin_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Omin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Omax_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Omax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmin_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Nmin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Nmax_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Nmax;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapi_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omin = { "Omin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapi_Parms, Omin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omax = { "Omax", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapi_Parms, Omax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmin = { "Nmin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapi_Parms, Nmin), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmin_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmax = { "Nmax", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapi_Parms, Nmax), METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmax_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MathUtilityLibrary_eventMathMapi_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Omax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_Nmax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::Function_MetaDataParams[] = {
		{ "Category", "MathUtilities" },
		{ "DisplayName", "int Mapping" },
		{ "Keywords", "Mapping" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/MathUtilityLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMathUtilityLibrary, nullptr, "MathMapi", nullptr, nullptr, sizeof(MathUtilityLibrary_eventMathMapi_Parms), Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMathUtilityLibrary_MathMapi()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMathUtilityLibrary_MathMapi_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMathUtilityLibrary_NoRegister()
	{
		return UMathUtilityLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UMathUtilityLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMathUtilityLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_MathUtilityModule,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMathUtilityLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMathUtilityLibrary_MathMapd, "MathMapd" }, // 1122391163
		{ &Z_Construct_UFunction_UMathUtilityLibrary_MathMapd_, "MathMapd_" }, // 315659513
		{ &Z_Construct_UFunction_UMathUtilityLibrary_MathMapf, "MathMapf" }, // 412329632
		{ &Z_Construct_UFunction_UMathUtilityLibrary_MathMapi, "MathMapi" }, // 4045494973
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMathUtilityLibrary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintThreadSafe", "" },
		{ "IncludePath", "BlueprintLibrary/MathUtilityLibrary.h" },
		{ "ModuleRelativePath", "Public/BlueprintLibrary/MathUtilityLibrary.h" },
		{ "ScriptName", "MathUtilityLibrary" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMathUtilityLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMathUtilityLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMathUtilityLibrary_Statics::ClassParams = {
		&UMathUtilityLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMathUtilityLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMathUtilityLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMathUtilityLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMathUtilityLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMathUtilityLibrary, 4195142078);
	template<> MATHUTILITYMODULE_API UClass* StaticClass<UMathUtilityLibrary>()
	{
		return UMathUtilityLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMathUtilityLibrary(Z_Construct_UClass_UMathUtilityLibrary, &UMathUtilityLibrary::StaticClass, TEXT("/Script/MathUtilityModule"), TEXT("UMathUtilityLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMathUtilityLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
